#include<bits/stdc++.h>
using namespace std;
int a;bool in,reg,mem[1024],st[16],tmp,ascllmode=0,diomode=1;int ouf=0,os=0,tot=0,zz=0,T=0,program[65536];char *namein="output.txt",*nameinput="intype.txt",*nameoutput="outtype.txt"; 
int main(int argc, char *argv[]){
	for (int i = 1; i < argc; i++)
	{
		char *inproccess=argv[i];
		switch (inproccess[0])
		{
		case '-':
			switch (inproccess[1])
			{
			case 'p':
				namein=argv[++i];
				break;
			case 'i':
				nameinput=argv[++i];
				break;
			case 'o':
				nameoutput=argv[++i];
			// case 'l':
			// 	if(argv[++i][0]=='0')memmode=0;else memmode=1;
			// 	break;
			case 'a':
				ascllmode=1;break;
			case 't':
				diomode=0;break;
			default:
			
				break;
			}
			break;
		
		default:
			throw "cmderr\n";
			break;
		}
	}
	freopen(namein,"r",stdin);
	cin>>a;cout<<"START\n";
	for(int i=0;a!=EOF;cin>>a,i++){
		program[i]=a;
	}if(diomode==0){freopen(nameinput,"r",stdin);
	freopen(nameoutput,"w",stdout);}
	for(int cl=0,T=0;;T++,cl=(cl+1)%1024){
		switch (program[cl])
		{
		case 0:break;
		case 1:if(reg==1){cout<<"\n"<<T<<"\n";system("pause");return 0;}break;
		case 2:if(zz>0){zz-=1;}else{cout<<"RTE-MEMDOWNFLOW";return -1;}break;
		case 3:if(zz<1023){zz+=1;}else{cout<<"RTE-MEMOVERFLOW";return -1;}break;
		case 4:reg=0;break;
		case 5:reg=1;break;
		case 6:reg=!reg;break;
		case 7:if(reg==1){cout<<"get input\n";cin>>reg;}break;
		case 8:reg&=mem[zz];break;
		case 9:mem[zz]=reg;break;
		case 10:if(tot<15){st[tot++]=reg;}else{cout<<"RTE-STACKOVERFLOW";return -1;}break;
		case 11:if(tot>0){reg&=st[--tot];}else{cout<<"RTE-STACKDOWNFLOW";return -1;}break;
		case 12:tmp=reg;break;
		case 13:if(reg==1){if(ascllmode==0)cout<<"put output:\n"<<tmp<<"\n";else if(os<7){os++;ouf*=2;ouf+=tmp;}else{os=0;ouf*=2;ouf+=tmp;cout<<(char)ouf;}}break;
		default:
			cout<<"SUMERR!";
			return -1;
		
		}
	}
	system("pause");
	return 0;
}
