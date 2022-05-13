// Including modules
# include<stdio.h>
# include<windows.h>
# include<time.h>

// Declearing the functions.
void recipt_withdrawal(int amount_withdraw, int balance_withdraw , int acc_no, char name[]);
void recipt_deposited(int amount_deposited, int balance_deposit , int acc_no, char name[]);




// Starting the main function.
int main(){

    // Declaring global variables.
    int pin = 1969, customer_pin, attemps = 1, wtc = 1, code, balance = 10000, acc_num = 1234, customer_an, amount, recipt_code, loginCode = 1;
    char customer_name[50] = "Harshal_Patil";

    printf("\n===============X===============X===============X===============X===============X===============X===============X===============");

    // Bank name;    
    printf("\n\n\t\t\t\t  ======= Welcome to Lakshimi Chit Fund =======\n\n");

    while(loginCode != 0){
        printf("\t\tPlease select an option from the following.\n\n");
        printf("\t\t1. Login to account.\n");
        printf("\t\t2. Create an account.\n");
        printf("\t\t3. Exit.\n");
        printf("\t\t(Please select the number correspond to the option.)\n\t\t");
        scanf("%d", &code);
        printf("\n\t\t-------------------------------------------------------------------------------------\n");
        switch(code){
            case 1:
                while(customer_pin != pin && customer_an != acc_num){
                    printf("\n\t\t\tPlease enter your account number: ");
                    scanf("%d", &customer_an);
                    printf("\t\t\tPlease enter your account Pin: ");
                    scanf("%d", &customer_pin);
                    if(customer_pin != pin){
                        Beep(700, 250);
                        printf("\t\t\tInvalid Account number or Pin \n");
                        printf("\t\t\tYou have only %d attempts left.\n\n", 3 - attemps);
                        attemps ++;
                    }

                    if(customer_pin != pin && customer_an != acc_num && attemps == 4){
                        printf("\t\t\tYour card has been blocked due to too many incorrent attempts.\n\t\t\tContact to head office to unblock it.\n");
                        exit(0);
                        break;
                    }
                }

                printf("\n\t\t\tWelcome Back, Mr. %s.\n\t\t\tWhat will you like to do today\n\n", customer_name);

                while(wtc != 0){
                    printf("\t\t\t\t\t--------------- Transactions to do ---------------\n");
                    printf("\t\t\t1. Change the account number\n");
                    printf("\t\t\t2. Change the pin number\n");
                    printf("\t\t\t3. Check the balance\n");
                    printf("\t\t\t4. Withdraw money\n");
                    printf("\t\t\t5. Deposite money\n");
                    printf("\t\t\t6. Exit\n");
                    printf("\n\t\t\t(Please select carefully, You cannot revert back)");
                    printf("\n\t\t\tPlease enter the code corresponding to the action you want to do: ");
                    scanf("%d", &code);

                    switch(code){
                        case 1:
                            printf("\n\t\tPlease enter the new account number: ");
                            scanf("%d", &acc_num);
                            wtc = 1;
                            printf("\t\tYour account number has been successfully changed\n");
                            break;

                        case 2:
                            printf("\t\t\tPlease enter the new pin number: ");
                            scanf("%d", &pin);
                            wtc = 1;
                            printf("\t\t\tYour pin number has been successfully changed\n\n");
                            break;

                        case 3:
                            printf("\t\t\tThe balance in your account is Rs.%d\n\n", balance);
                            break;

                        case 4:
                            printf("\t\t\tPlease enter the amount that you want to withdraw: ");
                            scanf("%d", &amount);
                            if (balance < amount){
                                printf("\t\t\tInsufficient Fund");
                                printf("\t\t\tYou have only Rs.%d amount in your account.\n\n", balance);
                                break;
                            }
                            else{
                                balance -= amount;
                                printf("\t\t\tYour withdrawal of Rs.%d has been successful\n", amount);
                                printf("\t\t\tDo you want the recipt of your transaction: \n");
                                printf("\t\t\t(Press '1' for YES and '0' for NO)\n\t\t\t");
                                scanf("%d", &recipt_code);
                                if(recipt_code == 1){
                                    recipt_withdrawal(amount, balance, acc_num, customer_name);
                                    break;
                                }else{
                                    printf("\t\t\tYour current balance is Rs.%d\n", balance);
                                    break;
                                }
                                break;
                            }

                        case 5:
                            printf("\t\t\tPlease enter the amount you want to debit: ");
                            scanf("%d", &amount);
                            balance += amount;
                            printf("\t\t\tYou have successfully debited Rs.%d in your account\n", amount);
                            printf("\t\t\tDo you want the recipt of your transaction: \n");
                            printf("\t\t\t(Press '1' for YES and '0' for NO)\n\t\t\t");
                            scanf("%d", &recipt_code);
                            if(recipt_code == 1){
                                recipt_deposited(amount, balance, acc_num, customer_name);
                                break;
                            }else{
                                printf("\n\t\t\tYour current balance is Rs.%d\n", balance);
                                break;
                            }
                            break;

                        case 6:
                            printf("\n\t\t\t\t\t--------------- Thank you ----------------\n");
                            printf("\t\t\t\t\t\tYou may have a nice day");
                            exit(0);
                            break;

                        default:
                            Beep(700, 250);
                            printf("Please enter a valid code\n");
                            break;
                    }                    
                    printf("\n\t\tDo you want to do any other changes or withdrawals related to your account\n\t\t\t('1' for YES and '0' for NO):\n\t\t\t");
                    scanf("%d", &wtc);
                    if(wtc == 0){
                        printf("\n\t\t\t\t\t--------------- Thank you ----------------\n");
                        printf("\t\t\t\t\t\tYou may have a nice day\n");
                        exit(0);
                    }
                }

                case 2:
                    printf("\n\t\t\tPlease set your pin number: ");
                    scanf("%d", &pin);
                    printf("\n\t\t\tPlease enter your Account number: ");
                    scanf("%d", &customer_an);
                    printf("\n\t\t\tPlease enter your name(enter underscore for spaces[_]): ");
                    scanf("%s", &customer_name);
                    printf("\n\t\t\tPlease enter your Amount: ");
                    scanf("%d", &balance);
                    printf("\n\t\t\tPlease press 1 to return to login page.");
                    scanf("%d", &loginCode);
                    if( loginCode == 1){
                        printf("\n\t\t\tYour account has been successfully created.\n\n");
                        attemps = 1;
                        break;
                    }else{
                        Beep(700, 250);
                        printf("\n\t\t\tInvalid code");
                        printf("\n\t\t\tYour account has not been created\n\n");
                        exit(0);
                    }

                case 3:
                    printf("\n\t\t\t\t\t--------------- Thank you ----------------\n");
                    printf("\t\t\t\t\t\tYou may have a nice day\n");
                    exit(0);
                }
    }

    return 0;
}




//Defining the functions.
void recipt_withdrawal(int amount_withdraw , int balance_withdraw , int acc_no, char name[]){
    //code for transaction.
    int transaction_code = 13539;

    // Declearing the time.
    time_t current_time;
    time(&current_time);

    // Incrementing the code.
    transaction_code++;

    printf("\t\t\t\t  ---------- Transaction Rcipt ----------\n\n");
    printf("\t\t\t\tTransaction Id\t\t\t\t%d\n", transaction_code);
    printf("\t\t\t\tDate\t\t\t\t\t%s\n\n", ctime(&current_time));
    printf("\t\t\t\tAccount No.\t\t\t\t%d\n\n", acc_no);
    printf("\t\t\t\tCustomer Name\t\t\t\t%s\n\n", name);
    printf("\t\t\t\tReq. withdrawal amount\t\t\tRs.%d\n", amount_withdraw);
    printf("\t\t\t\tAmount withdrawed\t\t\tRs.%d\n\n", amount_withdraw);
    printf("\t\t\t\tYour current Balance\t\t\tRs.%d\n\n", balance_withdraw);
    printf("\t\t\t\t\tThank you for banking with us!!\n\n");
    printf("\t\t\t\t\t\tHave a nice day\n\n");
    printf("\t\t\t\t  ---------------------------------------\n\n");

}

void recipt_deposited(int amount_deposited , int balance_deposit , int acc_no, char name[]){
    //code for transaction.
    int transaction_code = 16345;

    // Declearing the time.
    time_t current_time;
    time(&current_time);

    // Incrementing the code.
    transaction_code++;

    printf("\t\t\t\t  ---------- Transaction Rcipt ----------\n\n");
    printf("\t\t\t\tTransaction Id\t\t\t\t%d\n", transaction_code);
    printf("\t\t\t\tDate\t\t\t\t\t%s\n\n", ctime(&current_time));
    printf("\t\t\t\tAccount No.\t\t\t\t%d\n\n", acc_no);
    printf("\t\t\t\tCustomer Name\t\t\t\t%s\n\n", name);
    printf("\t\t\t\tReq. Deposit amount\t\t\tRs.%d\n", amount_deposited);
    printf("\t\t\t\tAmount Deposited\t\t\tRs.%d\n\n", amount_deposited);
    printf("\t\t\t\tYour current Balance\t\t\tRs.%d\n\n", balance_deposit);
    printf("\t\t\t\t\tThank you for banking with us!!\n\n");
    printf("\t\t\t\t\t\tHave a nice day\n\n");
    printf("\t\t\t\t  ---------------------------------------\n\n");

}