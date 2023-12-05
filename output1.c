#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<stdbool.h>
#define N 10
// structure for complex numbers 
struct complex{
    float a,b;
    char c,d;
};
// for calculating determinant through recursion
float determinant(float a[N][N], int n) {
    float det = 0, sign = 1, submatrix[N][N];
    if (n == 1) return a[0][0];
    for (int i = 0; i < n; i++) {
        int subi = 0;
        for (int j = 1; j < n; j++) {
            int subj = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                submatrix[subi][subj] = a[j][k];
                subj++;
            }
            subi++;
        }
        det += sign * a[0][i] * determinant(submatrix, n - 1);
        sign = -sign;
    }
    return det;
}
int main(){
    // taking the input for which type of equation
    printf("1=linear equation \n2=quadratic equation \n3=system of linear equation\n");
    printf("Enter the type of equation that you want to solve: ");
    int d;
    scanf("%d",&d);
    // for linear equation
    if(d==1){
        printf("the equation is in ax+b=0 form\n");//linear
        float a,b;
        printf("enter the value of a ");
        scanf("%f",&a);
        printf("enter the value of b ");
        scanf("%f",&b);
        // for infinte solution or non soltion
        if(a==0){
            if(b==0){
                printf("there are infinite solutions");
            }
            else{
                printf("the equation is inconsistent");
            }
        }
        // if not infinte solution or no solution then real solution
        else{
            float c=-b/a;
            printf("the solution of the equation is  %f",c);
        }
    }
    // for quadratic equation
    else if(d==2){
        float a,b,c;
        // taking input
        printf("equation is in ax^2+bx+c=0 form\n");//quadratic
         printf("enter the value of a ");
        scanf("%f",&a);
         printf("enter the value of b ");
        scanf("%f",&b);
         printf("enter the value of c ");
        scanf("%f",&c);
        // checking for no solution and infinte solution
        if(a==0){
          printf("the equation is not quadratic equation\n");
            if(b==0){
                if(c==0){
                    printf("the equation has infinite solutions\n ");
                    
                }
                else{
                    printf("the equation is inconsistent\n");
                                    }
            }
           else{
                float e=-c/b;
                printf("the solution of the equation is %f",e);
            }
        }
         // if not no solution or infinite solution then complex solution or real solution
         // using shree dharacharyas formula
         else{
             float discriminant=(b*b)-4*a*c;
         bool flag=true;
         // checking for discriminant for complex solution or real solution 
         if(discriminant<0){
              flag=true;
             discriminant=-1*discriminant;
         }
         else{
             flag =false;
         }
         float sd=sqrt(discriminant);
         // for only one solution when discriminant is 0
         if(discriminant==0){
             printf("this equation has only one root\n");
             float e=-b/2*a;
             printf("the root is %f",e);
         }
         // for real solution 
         else if(flag ==false){
            float sr1=(-b+sd)/2*a;
         float sr2=(-b-sd)/2*a;
             printf("the two roots of the equation are %f %f",sr1,sr2);
         }
         // for complex solution
         else if(flag==true){
             float sr1=-b/2*a;
             float sr2=sd/2*a;
             struct complex z;
             z.a=sr1;
             z.b=sr2;
             z.c='+';
             z.d='i';
             struct complex v;
             v.a=sr1;
             v.b=sr2;
             v.c='-';
             v.d='i';
             printf("the first solution of the equation is %f%c%c%f\n",z.a,z.c,z.d,z.b);
             printf("the second solution of the equation is  %f%c%c%f",v.a,v.c,v.d,v.b);
         }
         
         
    }}
    else if(d==3){
        int a;
        // taking input to get the number of equation
        printf("\nenter the number of equations ");
        scanf("%d",&a);
        // if there is single linear equation
        if(a==1){
            float b,c,e;
            printf("enter the equation in ax+c=0 format \n");
            printf("enter the value of a");
            scanf("%f",&b);
            printf("enter the value of c");
            scanf("%f",&c);
            // checking for no solution or infinite solution
            if(b==0){
                if(c==0){
                    printf("there are infinitely many solutions ");
                }
                else{
                    printf("there is no solution");
                }
            }
            // if not no solution or infinite solutions then real solution
            else{
                e=-c/b;
                printf("the solution of the equation is %f",e);
            }
            
        }
        // for 2 linear equations
        if(a==2){
            float b[N][N],c[N][N];
             // taking input
            printf("enter the equation in ax+by=c format \n");
            printf("enter the value of a1");
            scanf("%f",&b[0][0]);
            printf("enter the value of b1");
            scanf("%f",&b[0][1]);
            printf("enter the value of c1");
            scanf("%f",&c[0][0]);
            printf("enter the value of a2");
            scanf("%f",&b[1][0]);
            printf("enter the value of b2");
            scanf("%f",&b[1][1]);
            printf("enter the value of c2");
            scanf("%f",&c[1][0]);
            float detx[N][N],dety[N][N];
            float deta,detax,detay,r,q;
            // declaring matrix for coefficient of x and y
            for(int i=0;i<2;i++){
                    detx[i][0]=c[i][0];
                    detx[i][1]=b[i][1];
                    dety[i][1]=c[i][0];
                    dety[i][0]=b[i][0];
                    }
                // doing determinant
                deta=determinant(b,2);
                detax=determinant(detx,2);
                detay=determinant(dety,2);
            // for infinite solution or no solution 
            if(deta==0){
                    if(detax==0 && detay==0){
                        printf("\n there are infinitely many solution");
                        }
                    else{
                        printf("\n no solutions");
                    }
                    }
                // if not no solution or infinte solution then real solution 
                else{
                 r=detax/deta;
                 q=detay/deta;
                    printf("the solutions are \nthe value of x is %f \nthe value of y is %f ",r,q);
                }
        }
        // for three linear equation
        if(a==3){
            float b[N][N],c[N][N];
             // taking input element wise
            printf("enter the equation in ax+by+cz=d format \n");
            printf("enter the value of a1");
            scanf("%f",&b[0][0]);
            printf("enter the value of b1");
            scanf("%f",&b[0][1]);
            printf("enter the value of c1");
            scanf("%f",&b[0][2]);
            printf("enter the value of d1");
            scanf("%f",&c[0][0]);
            printf("enter the value of a2");
            scanf("%f",&b[1][0]);
            printf("enter the value of b2");
            scanf("%f",&b[1][1]);
            printf("enter the value of c2");
            scanf("%f",&b[1][2]);
            printf("enter the value of d2");
            scanf("%f",&c[1][0]);
            printf("enter the value of a3");
            scanf("%f",&b[2][0]);
            printf("enter the value of b3");
            scanf("%f",&b[2][1]);
            printf("enter the value of c3");
            scanf("%f",&b[2][2]);
            printf("enter the value of d3");
            scanf("%f",&c[2][0]);
            float detx[N][N],dety[N][N],detz[N][N];
            float deta,detax,detay,detaz,r,q,u;
            // declaring coefficient matrix for x,y,z
                for(int i=0;i<3;i++){
                    detx[i][0]=c[i][0];
                    detx[i][1]=b[i][1];
                    detx[i][2]=b[i][2];
                    dety[i][1]=c[i][0];
                    dety[i][0]=b[i][0];
                    dety[i][2]=b[i][2];
                    detz[i][0]=b[i][0];
                    detz[i][1]=b[i][1];
                    detz[i][2]=c[i][0];
                }
                // doing determinant
                deta=determinant(b,3);
                detax=determinant(detx,3);
                detay=determinant(dety,3);
                detaz=determinant(detz,3);
                // for no solution or infinite solutions
             if(deta==0){
                    if(detax==0 && detay==0 && detaz==0){
                        printf("\n there are infinitely many solutions ");
                        }
                    else{
                        printf("\n no solutions ");
                    }
                    }
            //if not infinte solution or no solution then real solution 
                else{
                 r=detax/deta;
                 q=detay/deta;
                u=detaz/deta;
                    printf("the solutions are \nthe value of x is %f \nthe value of y is %f \nthe value of z is %f",r,q,u);
                }
        }
    }
    // if input is not given in domain
    else{
        printf("\ninvalid input");
    }
    
    return 0;
}