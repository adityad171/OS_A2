#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define TWOD_COPY_SYSCALL 451

int main()
{
    int src_arr[2][5] = {{1, 2, 3, 4, 5},{6,7,8,9,0}};
    int dest_arr[2][5]; 

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
                if (src_arr[i][j] != dest_arr[i][j])
                {
                    printf("Error : LHS[%d][%d] != RHS[%d][%d}\n", i,j,i,j );
                    printf("%d", LHS[i][j]);
                    printf("%d", RHS[i][j]);
                    return;
                }
            }
        }
        printf("Message : Success LHS = RHS \n");
        }
    
    }

    return 0;
}
