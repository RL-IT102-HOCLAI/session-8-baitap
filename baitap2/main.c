#include <stdio.h>

#define MAX_SIZE 100

struct UserAccount
{
    int user_id;
    char username[50];
    int plan_type;
    int days_overdue;
    int active_devices;
    int monthly_fee;
    int actual_fee;
};

int main()
{
    struct UserAccount user_list[MAX_SIZE];
    int n;
    int i;
    int total_revenue = 0;
    int downgraded_count = 0;
    int extra_devices;

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
            printf("Loi: So tai khoan phai tu 1 den %d.\n",
                   MAX_SIZE);
        }
    } while (n < 1 || n > MAX_SIZE);

    for (i = 0; i < n; i++)
    {
        printf("\n===== NHAP TAI KHOAN %d =====\n", i + 1);

        printf("Nhap ma tai khoan: ");
        while (scanf("%d", &user_list[i].user_id) != 1)
        {
            while (getchar() != '\n');
            printf("Loi: Ma tai khoan phai la so nguyen. Nhap lai: ");
        }

        printf("Nhap ten tai khoan: ");
        scanf(" %49[^\n]", user_list[i].username);

        do
        {
            printf("Nhap goi dich vu (1-Free, 2-Personal, 3-Family): ");
            if (scanf("%d", &user_list[i].plan_type) != 1)
            {
                while (getchar() != '\n');
                user_list[i].plan_type = 0;
                printf("Loi: Vui long nhap so nguyen.\n");
            }
            else if (user_list[i].plan_type < 1 ||
                     user_list[i].plan_type > 3)
            {
                printf("Loi: Goi dich vu chi duoc la 1, 2 hoac 3.\n");
            }
        } while (user_list[i].plan_type < 1 ||
                 user_list[i].plan_type > 3);

        do
        {
            printf("Nhap so ngay no cuoc: ");
            if (scanf("%d", &user_list[i].days_overdue) != 1)
            {
                while (getchar() != '\n');
                user_list[i].days_overdue = -1;
                printf("Loi: Vui long nhap so nguyen.\n");
            }
            else if (user_list[i].days_overdue < 0)
            {
                printf("Loi: So ngay no cuoc khong duoc am.\n");
            }
        } while (user_list[i].days_overdue < 0);

        do
        {
            printf("Nhap so thiet bi dang ket noi: ");
            if (scanf("%d", &user_list[i].active_devices) != 1)
            {
                while (getchar() != '\n');
                user_list[i].active_devices = -1;
                printf("Loi: Vui long nhap so nguyen.\n");
            }
            else if (user_list[i].active_devices < 0)
            {
                printf("Loi: So thiet bi khong duoc am.\n");
            }
        } while (user_list[i].active_devices < 0);

        if (user_list[i].plan_type == 1)
        {
            user_list[i].monthly_fee = 0;
        }
        else if (user_list[i].plan_type == 2)
        {
            user_list[i].monthly_fee = 120000;
        }
        else
        {
            user_list[i].monthly_fee = 250000;
        }

        user_list[i].actual_fee = user_list[i].monthly_fee;
    }

    for (i = 0; i < n; i++)
    {
        if (user_list[i].days_overdue >= 3 &&
            user_list[i].plan_type != 1)
        {
            user_list[i].plan_type = 1;
            user_list[i].monthly_fee = 0;
            user_list[i].actual_fee = 0;
            downgraded_count++;
        }

        if (user_list[i].plan_type == 2 &&
            user_list[i].active_devices > 1)
        {
            extra_devices = user_list[i].active_devices - 1;
            user_list[i].actual_fee =
                user_list[i].monthly_fee + extra_devices * 30000;
        }

        total_revenue += user_list[i].actual_fee;
    }

    printf("\n");
    printf("===============================================================\n");
    printf("          STREAMFLOW SAAS - BAO CAO DOI SOAT CUOC\n");
    printf("===============================================================\n");
    printf("%-8s %-20s %-8s %-10s %-10s %-18s\n",
           "Ma TK", "Ten tai khoan", "Ma goi",
           "So TB", "No (ngay)", "Phi thuc thu");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-8d %-20.20s %-8d %-10d %-10d %15d VND\n",
               user_list[i].user_id,
               user_list[i].username,
               user_list[i].plan_type,
               user_list[i].active_devices,
               user_list[i].days_overdue,
               user_list[i].actual_fee);
    }

    printf("---------------------------------------------------------------\n");
    printf("Tong doanh thu thuc thu: %d VND\n", total_revenue);
    printf("So tai khoan bi ha cap ve Free: %d\n", downgraded_count);
    printf("===============================================================\n");

    return 0;
}
