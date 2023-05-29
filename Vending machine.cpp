using namespace std;
#include<iostream>

int main(){
	//price of the products (I took "prod" as the product variable)
	int prodA=20,prodB=30,prodC=40,prodD=50;
	
	//load 100 coins to the machine (To run the machine continuesly)
	int r1=100,r2=100,r5=100,r10=100;
	
	// coins in overflow bin
	int excr1=0,excr2=0,excr5=0,excr10=0;
	
    while(r1!=0 || r2!=0 || r5!=0 || r10!=0){
	
	//I took "num" as the variable for choice of the customer
	int num;
	
	//to select a product (A,B,C,D)
	cout<<"WELLCOME!"<<endl;
	cout<<"Choose your product"<<endl;
	cout<<endl;
	cout<<"product A : select 1\n";
	cout<<"product B : select 2\n";
	cout<<"product C : select 3\n";
	cout<<"product D : select 4\n";
	cout<<"Enter The choosed Product Number : ";
	cin>>num;
	
	while(num>4){	
	   cout<<"The entered number is invalid, please enter the Product Number again\n";
	   cout<<"Enter The Product Number : ";
	   cin>>num;
    }
    cout<<endl;
    
    // display the price of the product that customer selected.
    int price=0;
    switch(num){
    	case 1 : price=prodA; cout<<" price of product A  - RS:20"<<endl;break;
    	case 2 : price=prodB; cout<<" price of product B  - RS:30"<<endl;break;
    	case 3 : price=prodC; cout<<" price of product C  - RS:40"<<endl;break;
    	case 4 : price=prodD; cout<<" price of product D  - RS:50"<<endl;
	}
	
	cout<<"Put your coins in the slot"<<endl;
	
    //payment process variables (temporary variable = temp)
	int temp1=0,temp2=0,temp5=0,temp10=0;
	
	// balance calculating variables
	int temp1_1=0,temp2_1=0,temp5_1=0,temp10_1=0; 
	
	int count=0,payment=0,less=0;
	while(payment<price){
		if(count!=0){
			less=price-payment;
			cout<<"Rs."<<less<<" insufficient coins, please put coins for the rest"<<endl;
			cout<<"Put your coins in the slot"<<endl;
		}
	 cout<<"Number of RS. 1 coins - ";
	 cin>>temp1;

 	 cout<<"Number of RS. 2 coins - ";
	 cin>>temp2;

	 cout<<"Number of RS. 5 coins - ";
	 cin>>temp5;

	 cout<<"Number of RS. 10 coins - ";
	 cin>>temp10;
	 
	 //calculate the amount of all entered coins (temporary variable = temp)
	 payment+=(temp1*1+temp2*2+temp5*5+temp10*10);
	 cout<<"\n";
	 cout<<"You have pay :Rs."<<payment<<".00";
	 //add the entered coins to the appripriate denomination reserve
	 r1+=temp1;
	 r2+=temp2;
	 r5+=temp5;
	 r10+=temp10;
	 
	 temp1=0,temp2=0,temp5=0,temp10=0;
	 
	 count++;
	 cout<<endl;
	}
	
	
	//calculate the amount in the overflow bin
	int balance=0;
	balance=payment-price;
	temp10=balance/10;
	if(r10<temp10){
		temp10=r10;
	}
	balance=balance-temp10*10;
	temp5=balance/5;
	if(r5<temp5){
		temp5=r5;
	}
	balance=balance-temp5*5;
	temp2=balance/2;
	if(r2<temp2){
		temp2=r2;
	}
	balance=balance-temp2*2;
	temp1=balance/1;
	if(r1<temp1){
    }
    
    balance=payment-price;
    
    //handover the balance to the coin slot
    if(balance){
    	if(balance==0){
    		cout<<"Your balance is :Rs."<<balance<<".00"<<endl;
		}
		else{
			cout<<"Your balance is :Rs."<<balance<<".00"<<" Receive your balance "<<endl;
		}
		}else{
			cout<<"Sorry, machine out of change. Please pick your coin payment Rs. "<<payment<<".00 from the slot...."<<endl;
		}
		
		if(temp10>0){
			cout<<"Rs. 10 : "<<temp10<<endl;
		}
		if(temp5>0){
			cout<<"Rs. 5 : "<<temp5<<endl;
		}
		if(temp2>0){
			cout<<"Rs. 2 : "<<temp2<<endl;
		}
		if(temp1>0){
			cout<<"Rs. 1 : "<<temp1<<endl;
		}
		cout<<"Thank you!"<<endl;
		cout<<endl<<endl;
		
		//The balance will be deducted from the machine coin balance
	    r1-=temp1;
		r2-=temp2;
		r5-=temp5;
		r10-=temp10;
		
		//moves excess coins to the  overflow bin
        
	    if(r1>100){
		excr1+=(r1-100);
		r1=100;
	    }
	
		if(r2>100){
		excr2+=(r2-100);
		r2=100;
	    }
	
		if(r5>100){
		excr5+=(r5-100);
		r5=100;
	    }
	
		if(r10>100){
		excr10+=(r10-100);
		r10=100;
	    }
		
		//reintialize with 0
		temp1=0, temp2=0, temp5=0, temp10=0;
		//temp1_1=0, temp2_1=0, temp5_1=0, temp10_1=0;
		payment=0, balance=0;
	
		//start the process again if customer wants
		int password=0; //default value of pasword is given as 0 (Authorized pasword is 12345)
		cout<<"Enter the password to login "<<endl;
		cout<<"If you are a customer enter 0 to continue"<<endl;
		cin>>password;
		if(password==12345){
			break;//End the loop if the correct password entered
		}
		cout<<endl;
	}
	cout<<endl;
	
	int password;
	if(password){
		// if the vending machine runs out of change 
		cout<<"Out of change, sorry for the inconvenience"<<endl;
		cout<<"Please check the denomination reserves...."<<endl;
	}
	else{
		//if the owner end the process
		cout<<"Program terminated by the owner....."<<endl;
	}
	
	//Displys coins in each denomination reserve (vanding machine runs out of change or the process is terminated by the owner)
	cout<<"Coins in each denomination reserve"<<endl;
	cout<<"Number of coins in Rs. 1.00 reserve : "<<r1<<endl;
	cout<<"Number of coins in Rs. 2.00 reserve : "<<r2<<endl;
	cout<<"Number of coins in Rs. 5.00 reserve : "<<r5<<endl;
	cout<<"Number of coins in Rs. 10.00 reserve : "<<r10<<endl;
	
	//Displays coins in each overflow bin (vending machine runs out of coins or the process is terminated by the owner)
    cout<<"Coins in each overflow bin"<<endl;
	cout<<"Number of coins in Rs. 1.00 overflow bin : "<<excr1<<endl;
	cout<<"Number of coins in Rs. 2.00 overflow bin : "<<excr2<<endl;
	cout<<"Number of coins in Rs. 5.00 overflow bin : "<<excr5<<endl;
	cout<<"Number of coins in Rs. 10.00 overflow bin : "<<excr10<<endl;
	
return 0;
}
