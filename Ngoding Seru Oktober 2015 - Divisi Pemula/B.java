import java.util.Scanner;
public class B
{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		long nilai = in.nextLong();
		if(nilai >= 0 && nilai <= 100){
		    System.out.println("YA");
		}else{
		    System.out.println("TIDAK");
		}
	}
}