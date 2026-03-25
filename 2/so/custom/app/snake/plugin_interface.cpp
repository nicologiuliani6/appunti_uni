extern "C" int game_main(int argc, char** argv);

extern "C" int plugin_main(int argc, char** argv) {
    return game_main(argc, argv);
}

