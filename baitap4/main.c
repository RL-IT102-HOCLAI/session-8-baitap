#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

struct Subscription
{
    int user_id;
    char account_name[31];
    int plan_type;
    int active_devices;
    int max_devices;
    int days_overdue;
    int account_status;
};

int main()
{
    struct Subscription subscriptions[MAX_SIZE];
    int n, i;
    int downgraded_count = 0;
    int violation_count = 0;

    printf("============================================\n");
    printf("   STREAMFLIX SUBSCRIPTION AUDITOR\n");
    printf("============================================\n");

    do
    {
        printf("Nhap so luong tai khoan (1-%d): ", MAX_SIZE);
        scanf("%d", &n);

        if (n < 1 || n > MAX_SIZE)
        {
            printf("So luong khong hop le. Vui long nhap lai!\n");
        }
    } while (n < 1 || n > MAX_SIZE);

    for (i = 0; i < n; i++)
    {
        printf("\n--- Nhap tai khoan thu %d ---\n", i + 1);

        printf("User ID: ");
        scanf("%d", &subscriptions[i].user_id);

        printf("Ten tai khoan: ");
        scanf(" %30[^\n]", subscriptions[i].account_name);

        do
        {
            printf("Goi dich vu (1-Free, 2-Individual, 3-Family): ");
            scanf("%d", &subscriptions[i].plan_type);

            if (subscriptions[i].plan_type < 1 ||
                subscriptions[i].plan_type > 3)
            {
                printf("Goi dich vu khong hop le!\n");
            }
        } while (subscriptions[i].plan_type < 1 ||
                 subscriptions[i].plan_type > 3);

        printf("So thiet bi dang ket noi: ");
        scanf("%d", &subscriptions[i].active_devices);

        while (subscriptions[i].active_devices < 0)
        {
            printf("So thiet bi khong duoc am. Nhap lai: ");
            scanf("%d", &subscriptions[i].active_devices);
        }

        printf("So ngay no cuoc: ");
        scanf("%d", &subscriptions[i].days_overdue);

        while (subscriptions[i].days_overdue < 0)
        {
            printf("So ngay no khong duoc am. Nhap lai: ");
            scanf("%d", &subscriptions[i].days_overdue);
        }

        if (subscriptions[i].plan_type == 1 ||
            subscriptions[i].plan_type == 2)
        {
            subscriptions[i].max_devices = 1;
        }
        else
        {
            subscriptions[i].max_devices = 5;
        }

        subscriptions[i].account_status = 1;
    }

    for (i = 0; i < n; i++)
    {
        if (subscriptions[i].days_overdue > 3)
        {
            if (subscriptions[i].plan_type != 1)
            {
                downgraded_count++;
            }

            subscriptions[i].plan_type = 1;
            subscriptions[i].max_devices = 1;
            subscriptions[i].account_status = 0;
        }

        if (subscriptions[i].active_devices >
            subscriptions[i].max_devices)
        {
            violation_count++;
        }
    }

    printf("\n\n");
    printf("===============================================================\n");
    printf("             BAO CAO KIEM TOAN TAI KHOAN STREAMFLIX\n");
    printf("===============================================================\n");

    printf("%-8s %-20s %-12s %-12s %-10s %-12s\n",
           "User ID", "Account Name", "Goi dich vu",
           "Thiet bi", "No (ngay)", "Trang thai");

    printf("-----------------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        char plan_name[15];
        char status_name[15];
        char device_info[15];

        if (subscriptions[i].plan_type == 1)
        {
            strcpy(plan_name, "Free");
        }
        else if (subscriptions[i].plan_type == 2)
        {
            strcpy(plan_name, "Individual");
        }
        else
        {
            strcpy(plan_name, "Family");
        }

        if (subscriptions[i].account_status == 1)
        {
            strcpy(status_name, "Active");
        }
        else
        {
            strcpy(status_name, "Downgraded");
        }

        sprintf(device_info, "%d/%d",
                subscriptions[i].active_devices,
                subscriptions[i].max_devices);

        printf("%-8d %-20.20s %-12s %-12s %-10d %-12s\n",
               subscriptions[i].user_id,
               subscriptions[i].account_name,
               plan_name,
               device_info,
               subscriptions[i].days_overdue,
               status_name);

        if (subscriptions[i].active_devices >
            subscriptions[i].max_devices)
        {
            printf("  CANH BAO: Tai khoan %d vuot gioi han thiet bi!\n",
                   subscriptions[i].user_id);
        }
    }

    printf("\n===============================================================\n");
    printf("               BAO CAO THONG KE VAN HANH\n");
    printf("===============================================================\n");
    printf("Tong so tai khoan da ra soat: %d\n", n);
    printf("So tai khoan bi ha cap do no cuoc tren 3 ngay: %d\n",
           downgraded_count);
    printf("So tai khoan vi pham gioi han thiet bi: %d\n",
           violation_count);
    printf("===============================================================\n");

    return 0;
}
