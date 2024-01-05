#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int i, j;
void Base2toOthers(char str[]) {
    unsigned long long key10 = 0;
    int key8, size8, key16, size16, n=strlen(str), str8[100];
    char str16[100];
    // convert to Base 10
    for(i=0; i<n; i++){
        key10 = key10 + (str[i]-48)*pow(2,n-1-i);
    }
    printf("Base 10: %llu\n", key10);

    // convert to Base 8
    if(n%3 == 0)
        size8 = n/3;
    else
        size8 = n/3 + 1;
    
    j=size8 -1;
    for (i=n-1; i>=0; i-=3){
        if (i>=2)
            key8 = (str[i]-48) + (str[i-1]-48)*2 + (str[i-2]-48)*4;
        else{
            if (i==1) key8 = (str[i]-48) + (str[i-1]-48)*2;
            if (i==0) key8 = (str[i]-48);
        }

        if(key8 > 7) key8 +=2;
        str8[j] = key8;
        j--;    
    }
    printf("Base 8: ");
    for (i=0; i<size8; i++){
        printf("%d",str8[i]);
    }
    printf("\n");

    // convert to Base 16
    if(n%4 == 0)
        size16 = n/4;
    else
        size16 = n/4 + 1;
    j=size16-1;

    for (i=n-1; i>=0; i-=4){
        if(i>=3)
            key16 = (str[i]-48) + (str[i-1]-48)*2 + (str[i-2]-48)*4 + (str[i-3]-48)*8;
        else{
            if(i==2) key16 = (str[i]-48) + (str[i-1]-48)*2 + (str[i-2]-48)*4;
            if(i==1) key16 = (str[i]-48) + (str[i-1]-48)*2;
            if(i==0) key16 = (str[i]-48);
        }

        if(key16>9)
            str16[j]= key16+55;
        else
            str16[j]= key16+48;
        j--;
    }

    printf("Base 16: ");
    for(i=0; i<size16; i++){
        printf("%c", str16[i]);
    }
    printf("\n");
}

void Base8toOthers(char str[]) {
    unsigned long long key10 = 0;
    int key2, key16, n=strlen(str), str2[100];
    char str16[100];

    //convert to base 10
    for(i=0; i<n; i++){
        key10 += (str[i]-48)*pow(8,n-1-i);
    }
    printf("Base 10: %llu\n", key10);

    //convert to base 2
//Way1: convert from base 8
    // int count2;
    // j=0;
    // for(i=n-1; i>=0; i--){
    //     key2 = str[i]-48;
    //     count2 = 0;
    //     while(key2!=0){
    //         str2[j] = key2%2;
    //         key2 = key2/2;
    //         j++;
    //         count2++;
    //     }
    //     while(count2<3){
    //         str2[j] = 0;
    //         j++;
    //         count2++;
    //     }
    // }
//Way2: convert from base 10
    j=0;
    key2 = key10;
    while(key2!=0){
        str2[j] = key2%2;
        key2 = key2/2;
        j++;
    }

    printf("Base 2: ");
    for(i=j-1; i>=0; i--){
        printf("%d", str2[i]);
    }
    printf("\n");

    //convert to base 16 from Base 10
    j=0;
    key16 = key10;
    while(key16!=0){
        if(key16%16 > 9)
            str16[j] = (key16%16)+55;
        else
            str16[j] = (key16%16)+48;
        j++;
        key16 = key16/16;
    }

    printf("Base 16: ");
    for (i=j-1; i>=0; i--){
        printf("%c", str16[i]);        
    }
    printf("\n");
}

void Base10toOthers(char str[]) {
    unsigned long long key10;
    int key2, key8, key16, n=strlen(str), str8[100], str2[100];
    char str16[100];

    // change string to int number
    for(i=0; i<n; i++){
        key10 += (str[i]-48)*pow(10,n-1-i);
    }

    // convert to Base 2
    j=0;
    key2 = key10;
    while(key2!=0){
        str2[j] = key2%2;
        key2 = key2/2;
        j++;
    }

    printf("Base 2: ");
    for(i=j-1; i>=0; i--){
        printf("%d", str2[i]);
    }
    printf("\n");

    // convert to Base 8 
    j=0;
    key8 = key10;
    while(key8!=0){
        if(key8%8 > 7) 
            str8[j] = key8%8 +2;
        else
            str8[j] = key8%8;
        key8 = key8/8;
        j++;
    }

    printf("Base 8: ");
    for(i=j-1; i>=0; i--){
        printf("%d", str8[i]);
    }
    printf("\n");

    // convert to Base 16
    j=0;
    key16 = key10;
    while(key16!=0){
        if(key16%16 > 9)
            str16[j] = (key16%16)+55;
        else
            str16[j] = (key16%16)+48;
        j++;
        key16 = key16/16;
    }

    printf("Base 16: ");
    for (i=j-1; i>=0; i--){
        printf("%c", str16[i]);        
    }
    printf("\n");
}

void Base16toOthers(char str[]) {
    unsigned long long key10 = 0;
    int key2, key8, n=strlen(str), str8[100], str2[100];
    
    //convert to Base 10
    for(i=0; i<n; i++){
        if(str[i]>=65 && str[i]<=70)
            key10 = key10 + (str[i]-55)*pow(16,n-1-i);
        else if (str[i]>=48 && str[i]<=57)
            key10 = key10 + (str[i]-48)*pow(16,n-1-i);
    }
    printf("Base 10: %llu\n", key10);

    //convert to Base 8 from Base 10 
    j=0;
    key8 = key10;
    while(key8!=0){
        if(key8%8 > 7) 
            str8[j] = key8%8 +2;
        else
            str8[j] = key8%8;
        key8 = key8/8;
        j++;
    }

    printf("Base 8: ");
    for(i=j-1; i>=0; i--){
        printf("%d", str8[i]);
    }
    printf("\n");

    //convert to Base 2 from Base 10
    j=0;
    key2 = key10;
    while(key2!=0){
        str2[j] = key2%2;
        key2 = key2/2;
        j++;
    }

    printf("Base 2: ");
    for(i=j-1; i>=0; i--){
        printf("%d", str2[i]);
    }
    printf("\n");
}

int main(){
    int choose;
    char a[1000]; 
    back:system("cls") ;
	printf("1. Convert from Base 2 to Others Base.\n");
    printf("2. Convert from Base 8 to Others Base.\n");
    printf("3. Convert from Base 10 to Others Base.\n");
    printf("4. Convert from Base 16 to Others Base.\n");
    printf("5. Exit\n");
    scanf("%d", &choose);
    while(1){
        if(choose == 5) break;
        switch (choose)
        {
        case 1:
            printf("Input Binary String or \"back\" to return menu: ");
            scanf("%s", a);
            if(strcmp(a,"back") == 0) goto back;
            printf("Output: \n");
            Base2toOthers(a);
            break;
        case 2:
            printf("Input Octal String or \"back\" to return menu: ");
            scanf("%s", a);
            if(strcmp(a,"back") == 0) goto back;
            printf("Output: \n");
            Base8toOthers(a);
            break;
        case 3:
            printf("Input Decimal String or \"back\" to return menu: ");
            scanf("%s", a);
            if(strcmp(a,"back") == 0) goto back;
            printf("Output: \n");
            Base10toOthers(a);
            break;
        case 4:
            printf("Input Hexadecimal String or \"back\" to return menu: ");
            scanf("%s", a);
            if(strcmp(a,"back") == 0) goto back;
            printf("Output: \n");
            Base16toOthers(a);
            break;
        default:
            printf("You idiot!!! Input again: \n");
            goto back;
            break;
        }
    }
}
