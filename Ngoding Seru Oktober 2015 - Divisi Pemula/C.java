import java.util.Scanner;
public class C
{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int panjang = in.nextInt();
		if(panjang >= 1 && panjang <= 100){
		    Integer[] a = new Integer[panjang];
		    for(int i = 0; i < panjang; i++){
		        int angka = in.nextInt();
		        if(angka >= 1 && angka <= 100){
		            a[i] = angka;
		        }else{
		            System.exit(0);
		        }
		    }
		    for(int i = panjang - 1; i >= 0; i--){
		        System.out.print(a[i]);
		        if(i != 0){
		            System.out.print(",");
		        }
		    }
		}
	}
}