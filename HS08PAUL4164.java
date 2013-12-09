import java.io.*;
import java.util.Vector;
class HS08PAUL4164{
	private static int MAX= 10000000;
	static Vector<Integer> Primes=new Vector<Integer>();
	public static int precompute(){
		boolean flag[]=new boolean[MAX];
		int i,j;
		i=0;
		while(i<MAX){
			flag[i]=false;
			i++;
		}
		int limit;
		i=2;
		limit=(int)Math.sqrt(MAX);
		flag[0]=flag[1]=true;
		while(i<=limit){
			if(!flag[i]){
				Primes.add(i);
				j=i*i;
				while(j<MAX){
					flag[j]=true;
					j+=i;
				}
			}
			i++;
		}
		while(i<MAX){
			if(!flag[i]){
				Primes.add(i);
			}
			i++;
		}
		return Primes.size();
	}
	static boolean checkPrime(int value){
		int i,j,k;
		i=0;
		j=Primes.size()-1;
		while(i<=j){
			k=(i+j)/2;
			if(Primes.elementAt(k)>value){
				j=k-1;
			}
			else if(Primes.elementAt(k)<value){
				i=k+1;
			}
			else{
				return true;
			}
		}
		return false;
	}
	public static void main(String args[])throws IOException{
		BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
		precompute();
		int T;
		int N,value;
		int i,j;
		int count;
		int limit1,limit2;
		T=Integer.parseInt(I.readLine());
		while(T>0){
			count=0;
			N=Integer.parseInt(I.readLine());
			limit1=(int)Math.sqrt(N);
			limit2=(int)Math.sqrt(limit1);
			i=1;
			while(i<=limit1){
				j=1;
				while(j<=limit2){
					value=(int)Math.pow(i,2)+(int)Math.pow(j,4);
					if(value<=N && checkPrime(value)){
						count++;
					}
					j++;	
				}
				i++;
			}
			System.out.println(count);
			T--;
		}
	}
}
