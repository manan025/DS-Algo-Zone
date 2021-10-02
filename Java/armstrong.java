import java.util.*;
public class armstrong {
    Scanner sc=new Scanner(System.in);
    int dup;
    boolean armstron(int n){
        int s=0;
        dup=n;
        int r;
        while (dup>0){
            r=dup%10;
            s+=r*r*r;
            dup=dup/10;
        }
        return (n==s);
    }
    void display(){
        System.out.println("Enter size");
        int n=sc.nextInt();
        int []x=new int[n];
        System.out.println("Enter");
        for(int i=0;i<n;i++){
            x[i]=sc.nextInt();
            if(x[i]<=99||x[i]>999){
                System.out.println("Enter again");
                --i;
            }
        }
        for(int i=0;i<n;i++)
            if(armstron (x[i]))
                System.out.println("Armstrong"+x[i]);
    }
    public static void main(String []args){
        armstrong obj=new armstrong();
        obj.display();
    }
}
