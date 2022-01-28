int st_cm(char arr1[20],char arr2[20])
{
int flag=1,i;
for(i=0;arr1[i]!='\0'||arr2[i]!='\0';i++)
{
if(arr1[i]!=arr2[i])
flag=0;
}
return flag;
}
