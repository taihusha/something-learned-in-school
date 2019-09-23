import java.util.*;  
class lsc{
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);  
        String s1="ACCGGTCGAGATGCAG";
        String s2="GTCGTTCGGAATGCAT";
        System.out.println(lcs_length(s1, s2));
        System.out.print("hello");
        String name = s.nextLine();  
        System.out.println("姓名：" + name ); 
        s.close();
    }
    public static int lcs_length(String a,String b){
        int[][] len=new int[a.length()+1][b.length()+1];
        for(int i=1;i<=a.length();i++){
            for(int j=1;j<=b.length();j++){
                if(a.charAt(i-1)==b.charAt(j-1)){
                    len[i][j]=len[i-1][j-1]+1;
                }
                else if(len[i-1][j]>=len[i][j-1])
                {
                    len[i][j]=len[i-1][j];
                }
                else
                {
                    len[i][j]=len[i][j-1];
                }
            }
        }

        int aPos= a.length();
        int bPos= b.length();
        int commonLen=len[aPos][bPos];//此为最长公共子序列的长度
        int k=commonLen;
        char[] comon=new char[commonLen];
        //沿着先前构建的表进行回溯
        while(aPos!=0 && bPos!=0){
            if(len[aPos][bPos]==len[aPos-1][bPos-1]+1){
                comon[--k] = a.charAt(--aPos);
                bPos--;
            }
            else if(len[aPos-1][bPos]==len[aPos][bPos-1]){
                aPos--;
            }
            else{
                bPos--;
            }
        }
        //输出最长公共子序列
        for(int i=0;i<commonLen;i++){
            System.out.print(comon[i]);
        }
        System.out.println();    
        return commonLen;
    }
}