#include <stdio.h>

#define MAX_SIZE 100

struct UserAccount
{
    int account_id;
    int plan_type;
    int monthly_fee;
    int remaining_days;
    int active_devices;
};

int main()
{
    struct UserAccount accounts[MAX_SIZE];
    struct UserAccount temp;
    int n;
    int i;
    int j;
    int max_devices;
    int mrr_before = 0;
    int mrr_after = 0;
    int mrr_difference;

    do
    {
        printf("Nhap so luong tai khoan (1-%d): ", MAX_SIZE);

        if (scanf("%d", &n) != 1)
        {
            while (getchar() != '\n');
            n = 0;
            printf("Loi: Vui long nhap so nguyen.\n");
        }
        else if (n < 1 || n > MAX_SIZE)
        {
            printf("Loi: N phai nam trong khoang 1 den %d.\n",
                   MAX_SIZE);
        }
    } while (n < 1 || n > MAX_SIZE);

    for (i = 0; i < n; i++)
    {
        printf("\n===== TAI KHOAN %d =====\n", i + 1);

        printf("Nhap ma tai khoan: ");
        while (scanf("%d", &accounts[i].account_id) != 1)
        {
            while (getchar() != '\n');
            printf("Loi: Ma tai khoan phai la so nguyen. Nhap lai: ");
        }

        do
        {
            printf("Nhap goi (0-Free, 1-Standard, 2-Premium): ");

            if (scanf("%d", &accounts[i].plan_type) != 1)
            {
                while (getchar() != '\n');
                accounts[i].plan_type = -1;
                printf("Loi: Vui long nhap so nguyen.\n");
            }
            else if (accounts[i].plan_type < 0 ||
                     accounts[i].plan_type > 2)
            {
                printf("Loi: Goi chi duoc la 0, 1 hoac 2.\n");
            }
        } while (accounts[i].plan_type < 0 ||
                 accounts[i].plan_type > 2);

        printf("Nhap phi hang thang ban dau (VND): ");
        while (scanf("%d", &accounts[i].monthly_fee) != 1)
        {
            while (getchar() != '\n');
            printf("Loi: Phi phai la so nguyen. Nhap lai: ");
        }

        printf("Nhap so ngay con lai: ");
        while (scanf("%d", &accounts[i].remaining_days) != 1)
        {
            while (getchar() != '\n');
            printf("Loi: So ngay phai la so nguyen. Nhap lai: ");
        }

        printf("Nhap so thiet bi dang ket noi: ");
        while (scanf("%d", &accounts[i].active_devices) != 1)
        {
            while (getchar() != '\n');
            printf("Loi: So thiet bi phai la so nguyen. Nhap lai: ");
        }

        mrr_before += accounts[i].monthly_fee;
    }

    for (i = 0; i < n; i++)
    {
        if (accounts[i].active_devices <= 0)
        {
            accounts[i].active_devices = 1;
        }

        if (accounts[i].remaining_days <= 0)
        {
            accounts[i].plan_type = 0;
            accounts[i].monthly_fee = 0;
        }
        else
        {
            if (accounts[i].plan_type == 0)
            {
                accounts[i].monthly_fee = 0;
                max_devices = 1;
            }
            else if (accounts[i].plan_type == 1)
            {
                accounts[i].monthly_fee = 120000;
                max_devices = 2;
            }
            else
            {
                accounts[i].monthly_fee = 300000;
                max_devices = 5;
            }

            if (accounts[i].active_devices > max_devices)
            {
                accounts[i].active_devices = max_devices;
            }
        }

        mrr_after += accounts[i].monthly_fee;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if ((accounts[j].plan_type == 0 &&
                 accounts[j + 1].plan_type > 0) ||
                (accounts[j].plan_type > 0 &&
                 accounts[j + 1].plan_type > 0 &&
                 accounts[j].monthly_fee <
                 accounts[j + 1].monthly_fee))
            {
                temp = accounts[j];
                accounts[j] = accounts[j + 1];
                accounts[j + 1] = temp;
            }
        }
    }

    mrr_difference = mrr_before - mrr_after;

    printf("\n");
    printf("===============================================================\n");
    printf("           CLOUDSYNC STUDIO - AUDIT REPORT\n");
    printf("===============================================================\n");
    printf("%-12s %-10s %-15s %-15s %-12s\n",
           "Account ID", "Plan", "Monthly Fee", "Days Left", "Devices");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-12d %-10d %-15d %-15d %-12d\n",
               accounts[i].account_id,
               accounts[i].plan_type,
               accounts[i].monthly_fee,
               accounts[i].remaining_days,
               accounts[i].active_devices);
    }

    printf("---------------------------------------------------------------\n");
    printf("MRR truoc kiem toan:  %d VND\n", mrr_before);
    printf("MRR sau kiem toan:    %d VND\n", mrr_after);
    printf("Chenh lech MRR:       %d VND\n", mrr_difference);
    printf("===============================================================\n");

    return 0;
}
