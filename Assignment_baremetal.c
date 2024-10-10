/* NAME : vishal jadhav
   Description : calculate quaternion values
 */

#include <stdio.h>

struct vector
{
    int i,j,k;
};

struct quaternion         // create structure to contain values of scalar and vector(i,j,k)
{
    int s;
    struct vector v;
};

struct quaternion quat(int s,int i,int j,int k) 
{
    struct quaternion q;           //assign values to scalar and vector
    q.s = s;
    q.v.i = i;
    q.v.j = j;
    q.v.k = k;

    return q;
}

struct quaternion complement(struct quaternion q) 
{
    struct quaternion comp;      // create complement           
    comp.s = q.s;
    comp.v.i = q.v.i * -1;
    comp.v.j = q.v.j * -1;
    comp.v.k = q.v.k * -1;

    return comp;
}

struct quaternion multiply_quat(struct quaternion q,struct quaternion q_bar) 
{
    struct quaternion mul;                   // calculate multipication of quaternion

    mul.s = q.s * q_bar.s - q.v.i * q_bar.v.i - q.v.j * q_bar.v.j - q.v.k * q_bar.v.k;

    mul.v.i = q.s * q_bar.v.i + q.v.i * q_bar.s + q.v.j * q_bar.v.k - q.v.k * q_bar.v.j;

    mul.v.j = q.s * q_bar.v.j + q.v.j * q_bar.s + q.v.k * q_bar.v.i - q.v.i * q_bar.v.k;

    mul.v.k = q.s * q_bar.v.k + q.v.k * q_bar.s + q.v.i * q_bar.v.j - q.v.j * q_bar.v.i;

    return mul;
}

int dot_quat(struct quaternion q,struct quaternion q_bar) 
{
    int result = (q.s * q_bar.s) + (q.v.i * q_bar.v.i) + (q.v.j * q_bar.v.j) + (q.v.k * q_bar.v.k); //calculate dotproduct of quternion

    return result;
}

int main() 
{
    int s,i,j,k;

    printf("Enter the value of scalar : ");
    scanf("%d",&s);

    printf("Enter the vector values i,j,k :");
    scanf("%d %d %d",&i,&j,&k);

    struct quaternion q = quat(s,i,j,k);

    struct quaternion q_bar = complement(q);

    struct quaternion a=multiply_quat(q, q_bar);

    int b = dot_quat(q, q_bar);

    printf("q : (%d, %d, %d, %d)\n", q.s, q.v.i, q.v.j, q.v.k);
    printf("q_bar : (%d, %d, %d, %d)\n", q_bar.s, q_bar.v.i, q_bar.v.j, q_bar.v.k);
    printf("a : (%d, %d, %d, %d)\n", a.s, a.v.i, a.v.j, a.v.k);
    printf("b : %d\n", b);

    return 0;
}

