#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define TWOD_COPY_SYSCALL 451

int main()
{
    float src_arr[2][5] ;
    for (i = 0; i < 2; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                src[i][j]=i+j;
            }
    }
    
    float dest_arr[2][5]; 

    long sys_call_status;

    sys_call_status = syscall(TWOD_COPY_SYSCALL, src_arr, dest_arr, 5);

    if (sys_call_status != EFAULT)
    {
        printf("Message : System Call 451 successfuly invoked \n");
        {
        int i;
        for (i = 0; i < 2; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%f ", src_arr[i][j]);
                    printf("%f \n", dest_arr[i][j]);
//                 if (src_arr[i][j] != dest_arr[i][j])
//                 {
//                     printf("Error : LHS[%d][%d] != RHS[%d][%d}\n", i,j,i,j );
//                     printf("%d \n", src_arr[i][j]);
//                     printf("%d", dest_arr[i][j]);
//                     return;
//                 }
            }
        }
        printf("Message : Success LHS = RHS \n");
        }
    
    }

    return 0;
}
