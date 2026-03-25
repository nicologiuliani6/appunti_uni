public class Persona{
    String name;
    int eta;
    Persona(String name, int eta){
        this.name = name;
        this.eta = eta; 
    }
    public void presentati(){
        System.out.println("Ciao, mi chiamo " + this.name + " e ho " + this.eta + " anni");
    }
}