import java.util.Scanner;
import java.util.Random;

public class test                                                      {
	public static class lista{
		int val;
		lista next = null;
		public lista(int length){
			Random random = new Random();
			this.val = random.nextInt(100);
			if (length >0) {
				this.next = new lista(length-1);
			}
		}
		public void print(){
			System.out.println(this.val);
			if (this.next != null) this.next.print();
		}
	}
	public static void main(String[] args){
		try{
			Scanner scanner = new Scanner(System.in);

			lista L = new lista(10);
			L.print();
			scanner.close();
			System.exit(0);
		}
		catch (Exception e){
			System.out.println("ERRORE: " + e);
			System.exit(1);
		}
	}
}
