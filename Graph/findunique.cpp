#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool uniqueOccurrences(vector<int>& arr) {
        
// for(int i=0;i<arr.size();i++)
//   {
//       int count=0;
//     for(int j=0;j<arr.size();j++)
//     {
//         if(arr[j]==arr[i])
//         {
//             count++;
//         }
//     }
//     if(count==1)
//     {
//         return true;
//     }
//   }
        
//         return false;
        
        int size=arr.size();
    
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(arr[i]==1)
            {
                count++;
            }
        }
        if(count==1)
        {
            return true;
        }
        return false;
        
        
    }

int main()
{
  vector<int> arr;
  int size=7;
  for(int i=0;i<7;i++)
  {
      cin>>arr[i];
  }

   vector<int>temp;

     for(int i=0;i<size;i++)
     {
         temp[i]=0;
     }
        
        for(int i=0;i<size;i++)
        {
            temp[arr[i]]=temp[arr[i]]+1;
        }

        for(int i=0;i<size;i++)
        {
            cout<<temp[i]<<" ";
        }

   
//   for(int i=0;i<7;i++)
//   {
//       int count=0;
//     for(int j=0;j<7;j++)
//     {
//         if(arr[j]==arr[i])
//         {
//             count++;
//         }
//     }
//     if(count==1)
//     {
//         cout<<"Unique Element Is : "<<arr[i]<<endl;
//         break;
//     }
//   }


// int ans=0;
// for(int i=0;i<7;i++)
// {
//     ans=ans^arr[i];
// }
// cout<<ans<<endl;

// if(uniqueOccurrences(arr))
// {
//     cout<<"true";
//     return 0;
// }
// cout<<"No";
// return 0;

}