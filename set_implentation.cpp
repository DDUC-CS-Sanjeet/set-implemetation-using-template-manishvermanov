#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
template<class template_var>
class Myset
{
	int size;
	template_var *arr;
	
	public:
	
	Myset()   //default contructor
	{
	 size=0;	
	}
	
	Myset(int a)   // parametrised constructor
	{
		size=a;
		 arr= new template_var[size];
	}
	
	void get_element()    			//input function
	{
		cout<<"Enter elements of Set : ";
		for(int i=0;i<size;i++)
		{
			cin>>arr[i];
		}
		remove_duplicate_ele();
		
	}								//input function ends
	
	void remove_duplicate_ele()			//remove duplicate elements from set
	{
		sort(arr,arr+size);
		int temp[size],j=0;
		
		for(int i=0;i<size-1;i++)
		{
			if(arr[i]!=arr[i+1])
			{
				temp[j++]=arr[i];
			}
		}
		temp[j++]=arr[size-1];
		
		for(int i=0;i<j;i++)
		{
			arr[i]=temp[i];
		}
		
		size=j;
	}				//func end
	
	void print_set()			//display function
	{		
		cout<<"{";
		for(int i=0;i<size;i++)
		{
			cout<<arr[i];
			if(i<size-1)
			cout<<","	;	
		}		
		cout<<"}";
	}
	 
	int getcardinality()			//return cardinality of set
    {
    	return size;
	}
	
	int changecardinality(int n)	//modify cardinality of set 
	{
		size=n;
		return size;
	}
	
	void showcardinality()				//dispaly cardinality of set
	{
		cout<<"The cardinality of set entered is: "<<getcardinality();
	}
	
	Myset operator + (Myset obj)			//union function
	{
		Myset temp(size+obj.getcardinality());
		
		
		for(int i=0;i<size;i++)
		{
			temp.arr[i]=arr[i];
		}
		
		int k=0;
		for(int j=size;j<temp.getcardinality();j++)
		{
			temp.arr[j]=obj.arr[k];
			k++;
		}
		temp.remove_duplicate_ele();
		
		return temp;
	}													//end 
	
	Myset operator *(Myset obj)			//intersection function
	{	
		int n;
		if(size<obj.size)
			 n=size;
		else
			 n=obj.size;
			
		Myset temp(n);
		int i,j,k=0;
		
		for(i=0;i<size;i++)
		{
			for(j=0;j<obj.size;j++)
			{
				if(arr[i]==obj.arr[j])
					temp.arr[k++]=arr[i];
			}
		}
		temp.changecardinality(k);	
		return temp;
	}												//end
	
	Myset operator-(const Myset obj2)  		//differnce function
    {
    	int n=size;
    	int k=0;
    	Myset temp(n);
		for(int i=0;i<size;i++)
		{
			int flag=0;
			for(int j=0;j<obj2.size;j++)
			{
				if(arr[i]==obj2.arr[j])
				{
					flag=1;	
					break;		
				}
				
			}
			if(!flag)
				{
					temp.arr[k++]=arr[i];
				}
		 } 
    
    	temp.remove_duplicate_ele();
    
    	temp.changecardinality(k);
    	return (temp);
	}									//end
	
	Myset operator^( Myset obj2) 			//symmetric differnce
	{
		int n=(obj2.getcardinality()>=size)?obj2.getcardinality() : size;
		Myset union_temp(size+obj2.getcardinality());
		Myset intersection_temp(n);
		Myset temp(n);
		
		union_temp=*this +obj2;
		intersection_temp=*this * obj2;
		temp=union_temp-intersection_temp;
		
		temp.remove_duplicate_ele();
		
    	return (temp);
	}															//end
	
	
	bool operator==(Myset obj2)			//checking if sets are equal or not
	{	
		
		if(size==obj2.getcardinality())
		{
			int flag1,flag2=1;
		     
	      	for(int i=0;i<size&&flag2;i++)
			{
				flag1=0;
				for(int j=0;j<size;j++)
				{	
					if(arr[i]==obj2.arr[j])
			  	  {   
						 flag1=1;	
						 break; 
			   		}
		
				}
				if(flag1==0)
				{
					flag2=0;
				}
			}
		
		if(flag2)
			return true;
		else
			return false;
		}
		else
		{
			cout<<"\nThe size of both the sets is different therefore ";
			return false;
		}
		
	}														//end
	
	Myset& operator=(const Myset& obj2) 			//assignment operator overload
	{
		size=obj2.size;
		arr=new template_var[size];
		for(int i=0;i<size;i++)
		{
			arr[i]=obj2.arr[i];
		}
		return (*this);
	} 																	//end
	
	void genpowerset(int card) 							//gives powerset
	{
		cout<<"The power set is : {";
		for(int i=0;i<pow(2,card);i++)
		{
			cout<<"{";
			for(int t=i,j=0;j<card;j++)
			{
				if(t&1)
				{
					cout<<arr[j]<<" ";
				}
				t=t>>1;
				
			}
			cout<<"}";
			cout<<((i<pow(2,card)-1)?',':'}');
		}
		cout<<"\n";
		cout<<"\nThe cardianality of power set is: "<<pow(2,size);	
	}												//funtion end
	
};					//class end

	template <typename template_var>   //again prototype for template as it is outside class
	
	void all_function(template_var typeVar)		//contain all choices
	{
		int size1,size2,choice;
 		char answer;
    
	    cout<<"\nEnter the size of set A: ";
        cin>>size1;
        Myset<template_var> obj1(size1);
       	obj1.get_element();
       	cout<<"Set A : ";
       	obj1.print_set();
       		
       	cout<<"\n\nEnter the size of set B: ";
       	cin>>size2;
        Myset<template_var> obj2(size2);
        obj2.get_element();
        cout<<"Set B : ";
        obj2.print_set();
		
		Myset<template_var> obj3;
       
	do
	{
       	
        cout<<"\n\n                   OPERATIONS ON SETS";
		cout<<endl;
		cout<<"\nEnter the number to perform following operations: ";
		cout<<"\n";
		cout<<"\n1.Union of two sets";
		cout<<"\n2.Intersection of two sets";
		cout<<"\n3.Difference of two sets";
		cout<<"\n4.Symmetric Difference of two sets";
		cout<<"\n5.Check the equality of two sets";
		cout<<"\n6.Copy values of one set to another";
		cout<<"\n7.Generate power set : ";
		cout<<"\n8.Find cardinality of set :";
		          
		cout<<endl;
		cout<<"\nEnter the choice: ";
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
			case 1:
				{
					obj3=obj1+obj2;
					obj3.print_set();        //union operation
					break;
				}
			case 2:
				{
					obj3=obj1*obj2; 
					obj3.print_set();        //intersection operation
					break;
				}
			case 3:
				{
					obj3=obj1-obj2;	
					obj3.print_set();	    //Difference operation
					break;
				}
			case 4:
				{
					obj3=obj1^obj2;
					obj3.print_set();						//Symmetric Difference operation
					break;
				}
			case 5:
				{
				 if(obj1==obj2)				//Assignment operation
        	   		 cout<<"Sets are same.";
               	 else
             		cout<<"Sets are NOT same";
             		break;
				}
			case 6:
				{	char sub_choice;
					cout<<"Copy Set A or Set B ? (press A/B) ";
					cin>>sub_choice;
					
					switch(sub_choice)
					{
					case 'a' :
					case 'A' : obj3=obj1;
								obj3.print_set();
								break;
					case 'b' :
					case 'B' : obj3=obj2;
								obj3.print_set();
								break;
								
									//copying values of one set to another
					
					}
					break;
				}
			case 7:
				{
					char subchoice;
					cout<<"\n 1.Generate power set of set A";
					cout<<"\n 2.Generate power set of set B";
					cout<<"\nPress A or B !";       //generating power set 
					cin>>subchoice;
				
						switch(subchoice)
						{
							case 'A':
							case 'a':
							{
								int size=obj1.getcardinality();
								obj1.genpowerset(size);
								break;
					   	    }
							case 'B':
							case 'b':
							{
								int size=obj2.getcardinality();
								obj2.genpowerset(size);
								break;
							}
							default:
							{
								cout<<"Enter correct choice!"	;
							}
							
					    } 
					    break;
	            }
	        case 8:
	        	{
					//Finding cardinality of set
					cout<<"\n 1.Find cardinality of set A";
					cout<<"\n 2.Find cardinality of set B";
					char subchoice;
					cout<<"\nPress A or B ! ";
					cin>>subchoice;
				
						switch(subchoice)
						{
							case 'A':
							case 'a':
							{
								obj1.showcardinality();
								
								break;
					   	    }
							case 'B':
							case 'b':
							{
								obj2.showcardinality();
								
								break;
							}
							default:
							{
								cout<<"\nEnter correct choice!";
								
							}
							
					    } 
					    break;
				}
	            
	        default:
	            {
	            	cout<<"Enter correct choice!!";
	            	break;
				}
			}
			
			cout<<"\n\nDo you wish to continue(Press 'Y' for YES and 'N' for NO.)";
			cin>>answer;	
   	
   	}while(answer=='Y'||answer=='y');
   	 
	}								//end
	

int main()
{
	int choice1;
    
    	int i;
    	char c;
    	float f;
    	
    	cout<<"                     DATA-TYPE SELECTION  \n";
    	cout<<"1. int type \n";
    	cout<<"2. char type \n";
    	cout<<"3. float type \n";
    	
    	cout<<"\nEnter your choice for datatype : ";
    	cin>>choice1;
    	
    	switch(choice1)
    	{			
    		case 1: all_function(i);
    				break;
    				
    		case 2: all_function(c);
    				break;
    				
    		case 3: all_function(f);
    				break;
    				
    		default: cout<<"Invalid choice!!!";
  		
		}
   	 
   	 

	return 0;
}
