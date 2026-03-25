#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

const std::vector<std::string> specialLabels = {"SP", "ARG", "LCL"};

bool isLabel(const std::string &line) {
    return (line[0] == '@' || (line[0] == '(' && line.back() == ')'));
}

void processLabels(const std::string &filename, std::vector<std::string> &lines, std::unordered_map<std::string, std::string> &labelMap, int &labelCounter) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Errore nell'aprire il file: " << filename << std::endl;
        return; // Esci dalla funzione invece di chiamare exit()
    }

    std::string line;
    while (std::getline(file, line)) {
        // Rimuove spazi bianchi all'inizio e alla fine della riga
        line.erase(line.find_last_not_of(" \t\n\r") + 1);
        line.erase(0, line.find_first_not_of(" \t\n\r"));

        // Salta righe vuote o commenti
        if (line.empty() || line.substr(0, 2) == "//") {
            continue;
        }

        // Controlla se è un'etichetta
        if (line[0] == '@' || (line[0] == '(' && line.back() == ')')) {
            std::string label;
            if (line[0] == '@') {
                label = line.substr(1); // Rimuove il '@'
            } else { // Rimuove '(' e ')'
                label = line.substr(1, line.size() - 2);
            }

            // Se l'etichetta è SP, ARG o LCL, non modificarla
            if (std::find(specialLabels.begin(), specialLabels.end(), label) != specialLabels.end()) {
                continue; // Non modificare le etichette speciali
            }

            // Se l'etichetta non è già mappata, assegnale un valore univoco
            if (labelMap.find(label) == labelMap.end()) {
                labelMap[label] = "et" + std::to_string(labelCounter++);
            }

            // Sostituisci l'etichetta nel contenuto
            if (line[0] == '@') {
                line = "@" + labelMap[label];
            } else {
                line = "(" + labelMap[label] + ")";
            }
        }

        lines.push_back(line);
    }

    file.close();
}

void compareFiles(const std::vector<std::string> &file1Lines, const std::vector<std::string> &file2Lines) {
    size_t maxLines = std::max(file1Lines.size(), file2Lines.size());
    bool isEqual = true;

    for (size_t i = 0; i < maxLines; ++i) {
        std::string line1 = (i < file1Lines.size()) ? file1Lines[i] : "EOF";
        std::string line2 = (i < file2Lines.size()) ? file2Lines[i] : "EOF";

        if (isLabel(line1) && isLabel(line2)) {
            continue; // Le righe sono etichette, non fare nulla
        }

        if (line1 == line2) {
            continue;
        } else {
            isEqual = false;
            std::cout << "Riga " << i + 1 << ": DIVERSA (File1: " << line1 << ", File2: " << line2 << ")" << std::endl;
        }
    }

    if (isEqual) {
        std::cout << "Tutto OK: I file sono uguali." << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <file1> <file2>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string file1 = argv[1];
    std::string file2 = argv[2];

    std::unordered_map<std::string, std::string> labelMap;
    std::vector<std::string> file1Lines, file2Lines;
    int labelCounter = 1;

    processLabels(file1, file1Lines, labelMap, labelCounter);
    processLabels(file2, file2Lines, labelMap, labelCounter);

    compareFiles(file1Lines, file2Lines);

    return 0;
}
