import java.io.*;
import java.math.*;
class JULKA54{
    public static void main(String args[])throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String str1,str2;
        for(int i=0;i<10;i++){
            str1=br.readLine();
            str2=br.readLine();
            BigInteger b1=new BigInteger(str1);
            BigInteger b2=new BigInteger(str2);
            BigInteger TWO=new BigInteger("2");
            BigInteger ans1=b1.add(b2).divide(TWO);
            BigInteger ans2=b1.subtract(ans1);
            System.out.println(ans1.toString());
            System.out.println(ans2.toString());
        }
    }
}
