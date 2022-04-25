#include<stdio.h>
void qs(int a[20],int left,int right)
{
    if(left<right)
    {
        int pivot = a[left];
        int l=left;
        int r=right;
        while(l<r)
        {
            while(pivot>=a[l] && l<right)
                l++;
            while(pivot<a[r])
                r--;
            if(l<r)
            {
                int temp=a[l];
                a[l]=a[r];
                a[r]=temp;
            }
        }
        a[left]=a[r];
        a[r]=pivot;
        qs(a,left,r-1);
        qs(a,r+1,right);
    }
    for(int i=0;i<=right;++i)
        printf("%d  ",a[i]);
    printf("\n");
}
void main()
{
    int n,a[20];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    qs(a,0,n-1);
}
