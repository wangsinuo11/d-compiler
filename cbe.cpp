#include<bits/stdc++.h>
using namespace std;
char k;
string expr;
char *namein,*nameout="a.out";
int tot=0,mem,nst,tmp=1,t,memdelay;
bool st[1024],memmode,o2mode,macode=1;
int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		char *inproccess=argv[i];
		switch (inproccess[0]) {
			case '-':
				switch (inproccess[1]) {
					case 'i':
						namein=argv[++i];
						break;
					case 'o':
						nameout=argv[++i];
						break;
						// case 'l':
						// 	if(argv[++i][0]=='0')memmode=0;else memmode=1;
						// 	break;
					case 'a':
						macode=0;
						break;
					case 'O':
						o2mode=1;
						break;
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
	freopen(nameout,"w",stdout);
	if(!o2mode) {
		cin>>k;
		while(k!='#') {
			if(k=='[') {
				cin>>mem;
				t=mem;
				cin>>k;
				while(k!=';') {
					switch(k) {
						case '0':
							if(macode==0)cout<<"0\n";
							else cout<<"4\n";
							break;
						case '1':
							break;
						case '!':
							cin>>k;
							if(k=='(') {
								st[tot++]=1;
								tmp++;
								if(macode==0)cout<<"PUSH\n1\n";
								else cout<<"10\n5\n";
							} else if (k=='[') {
								cin>>mem;
								for(int i=mem; i<nst; i++) {
									if(macode==0)cout<<"L\n";
									else cout<<"2\n";
								}
								for(int i=nst; i<mem; i++) {
									if(macode==0)cout<<"R\n";
									else cout<<"3\n";
								}
								nst=mem;
								if(memmode) {
									if(macode==0)cout<<"PUSH\n1\nLD\n";
									else cout<<"10\n5\n8\n";
									for(int i=0; i<memdelay; i++)if(macode==0)cout<<"U\n";
										else cout<<"0\n";
									if(macode==0)cout<<"NOT\nPOP\n";
									else cout<<"6\n11\n";
								} else if(macode==0)cout<<"PUSH\n1\nLD\nNOT\nPOP\n";
								else cout<<"10\n5\n8\n6\n11\n";
							} else throw "syntax error!";
							break;
						case '(':
							st[tot++]=0;
							break;
						case '[':
							cin>>mem;
							for(int i=mem; i<nst; i++) {
								if(macode==0)cout<<"L\n";
								else cout<<"2\n";
							}
							for(int i=nst; i<mem; i++) {
								if(macode==0)cout<<"R\n";
								else cout<<"3\n";
							}
							nst=mem;
							if(macode==0)cout<<"LD\n";
							else cout<<"8\n";
							break;
						case ']':
							break;
						case ')':
							if(st[--tot]==1) {
								if(macode==0)cout<<"NOT\nPOP\n";
								else cout<<"6\n11\n";
								tmp--;
							}
							break;
					}
					cin>>k;
				}
				mem=t;
				for(int i=mem; i<nst; i++) {
					if(macode==0)cout<<"L\n";
					else cout<<"2\n";
				}
				for(int i=nst; i<mem; i++) {
					if(macode==0)cout<<"R\n";
					else cout<<"3\n";
				}
				nst=mem;
				if(macode==0)cout<<"ST\n1\n";
				else cout<<"9\n5\n";
				cin>>k;
			} else if(k=='i') {
				cin>>k>>k>>k>>k>>mem>>k>>k;
				t=mem;
				if(k==';') {
					if(macode==0)cout<<"1\nIN\n";
					else cout<<"5\n7\n";
				} else {
					cin>>k;
					while(k!=';') {
						switch(k) {
							case '0':
								if(macode==0)cout<<"0\n";
								else cout<<"4\n";
								break;
							case '1':
								break;
							case '!':
								cin>>k;
								if(k=='(') {
									st[tot++]=1;
									tmp++;
									if(macode==0)cout<<"PUSH\n1\n";
									else cout<<"10\n5\n";
								} else if (k=='[') {
									cin>>mem;
									for(int i=mem; i<nst; i++) {
										if(macode==0)cout<<"L\n";
										else cout<<"2\n";
									}
									for(int i=nst; i<mem; i++) {
										if(macode==0)cout<<"R\n";
										else cout<<"3\n";
									}
									nst=mem;
									if(memmode) {
										if(macode==0)cout<<"PUSH\n1\nLD\n";
										else cout<<"10\n5\n8\n";
										for(int i=0; i<memdelay; i++)if(macode==0)cout<<"U\n";
											else cout<<"0\n";
										if(macode==0)cout<<"NOT\nPOP\n";
										else cout<<"6\n11\n";
									} else if(macode==0)cout<<"PUSH\n1\nLD\nNOT\nPOP\n";
									else cout<<"10\n5\n8\n6\n11\n";
								} else throw "syntax error!";
								break;
							case '(':
								st[tot++]=0;
								break;
							case '[':
								cin>>mem;
								for(int i=mem; i<nst; i++) {
									if(macode==0)cout<<"L\n";
									else cout<<"2\n";
								}
								for(int i=nst; i<mem; i++) {
									if(macode==0)cout<<"R\n";
									else cout<<"3\n";
								}
								nst=mem;
								if(macode==0)cout<<"LD\n";
								else cout<<"8\n";
								break;
							case ']':
								break;
							case ')':
								if(st[--tot]==1) {
									if(macode==0)cout<<"NOT\nPOP\n";
									else cout<<"6\n11\n";
									tmp--;
								}
								break;
						}
						cin>>k;
					}
					if(macode==0)cout<<"IN\n";
					else cout<<"7\n";
				}
				mem=t;
				for(int i=mem; i<nst; i++) {
					if(macode==0)cout<<"L\n";
					else cout<<"2\n";
				}
				for(int i=nst; i<mem; i++) {
					if(macode==0)cout<<"R\n";
					else cout<<"3\n";
				}
				nst=mem;
				if(macode==0)cout<<"ST\n1\n";
				else cout<<"9\n5\n";
				cin>>k;
			} else if(k=='o') {
				cin>>k>>k>>k>>k;
				cin>>k;
				if(macode==0)cout<<"1\n";
				else cout<<"5\n";
				while(k!=';'&&k!='=') {
					switch(k) {
						case '0':
							if(macode==0)cout<<"0\n";
							else cout<<"4\n";
							break;
						case '1':
							break;
						case '!':
							cin>>k;
							if(k=='(') {
								st[tot++]=1;
								tmp++;
								if(macode==0)cout<<"PUSH\n1\n";
								else cout<<"10\n5\n";
							} else if (k=='[') {
								cin>>mem;
								for(int i=mem; i<nst; i++) {
									if(macode==0)cout<<"L\n";
									else cout<<"2\n";
								}
								for(int i=nst; i<mem; i++) {
									if(macode==0)cout<<"R\n";
									else cout<<"3\n";
								}
								nst=mem;
								if(memmode) {
									if(macode==0)cout<<"PUSH\n1\nLD\n";
									else cout<<"10\n5\n8\n";
									for(int i=0; i<memdelay; i++)if(macode==0)cout<<"U\n";
										else cout<<"0\n";
									if(macode==0)cout<<"NOT\nPOP\n";
									else cout<<"6\n11\n";
								} else if(macode==0)cout<<"PUSH\n1\nLD\nNOT\nPOP\n";
								else cout<<"10\n5\n8\n6\n11\n";
							} else throw "syntax error!";
							break;
						case '(':
							st[tot++]=0;
							break;
						case '[':
							cin>>mem;
							for(int i=mem; i<nst; i++) {
								if(macode==0)cout<<"L\n";
								else cout<<"2\n";
							}
							for(int i=nst; i<mem; i++) {
								if(macode==0)cout<<"R\n";
								else cout<<"3\n";
							}
							nst=mem;
							if(macode==0)cout<<"LD\n";
							else cout<<"8\n";
							break;

						case ']':
							break;
						case ')':
							if(st[--tot]==1) {
								if(macode==0)cout<<"NOT\nPOP\n";
								else cout<<"6\n11\n";
								tmp--;
							}
							break;
						default:
							break;
					}
					cin>>k;
				}
				if(macode==0)cout<<"OUT\n1\n";
				else cout<<"12\n5\n";
				if(k==';') {
					if(macode==0)cout<<"OUTT\n";
					else cout<<"13\n";
					cin>>k;
				} else {
					while(k!=';') {
						switch(k) {
							case '0':
								if(macode==0)cout<<"0\n";
								else cout<<"4\n";
								break;
							case '1':
								break;
							case '!':
								cin>>k;
								if(k=='(') {
									st[tot++]=1;
									tmp++;
									if(macode==0)cout<<"PUSH\n1\n";
									else cout<<"10\n5\n";
								} else if (k=='[') {
									cin>>mem;
									for(int i=mem; i<nst; i++) {
										if(macode==0)cout<<"L\n";
										else cout<<"2\n";
									}
									for(int i=nst; i<mem; i++) {
										if(macode==0)cout<<"R\n";
										else cout<<"3\n";
									}
									nst=mem;
									if(memmode) {
										if(macode==0)cout<<"PUSH\n1\nLD\n";
										else cout<<"10\n5\n8\n";
										for(int i=0; i<memdelay; i++)if(macode==0)cout<<"U\n";
											else cout<<"0\n";
										if(macode==0)cout<<"NOT\nPOP\n";
										else cout<<"6\n11\n";
									} else if(macode==0)cout<<"PUSH\n1\nLD\nNOT\nPOP\n";
									else cout<<"10\n5\n8\n6\n11\n";
								} else throw "syntax error!";
								break;
							case '(':
								st[tot++]=0;
								break;
							case '[':
								cin>>mem;
								for(int i=mem; i<nst; i++) {
									if(macode==0)cout<<"L\n";
									else cout<<"2\n";
								}
								for(int i=nst; i<mem; i++) {
									if(macode==0)cout<<"R\n";
									else cout<<"3\n";
								}
								nst=mem;
								if(macode==0)cout<<"LD\n";
								else cout<<"8\n";
								break;
							case ']':
								break;
							case ')':
								if(st[--tot]==1) {
									if(macode==0)cout<<"NOT\nPOP\n";
									else cout<<"6\n11\n";
									tmp--;
								}
								break;
						}
						cin>>k;
					}
					if(macode==0)cout<<"OUTT\n";
					else cout<<"13\n";
					cin>>k;
				}
				
			} else if(k=='h') {
				cin>>k>>k>>k>>k;
				if(k==';') {
					if(macode==0)cout<<"1\nHALT\n#";
					else cout<<"5\n1\n";
					return 0;
				} else if(k=='=') {
					cin>>k>>mem>>k>>k;
					for(int i=mem; i<nst; i++) {
						if(macode==0)cout<<"L\n";
						else cout<<"2\n";
					}
					for(int i=nst; i<mem; i++) {
						if(macode==0)cout<<"R\n";
						else cout<<"3\n";
					}
					nst=mem;
					if(memmode) {
						if(macode==0)cout<<"1\nLD\n";
						else cout<<"5\n8\n";
						for(int i=0; i<memdelay; i++)if(macode==0)cout<<"U\n";
							else cout<<"0\n";
						if(macode==0)cout<<"HALT\n";
						else cout<<"1\n";
					}	else if(macode==0)cout<<"1\nLD\nHALT\n";
					else cout<<"5\n8\n1\n";
				} else throw "syntax error!";
				cin>>k;
			}

		}
		for(int i=0; i<nst; i++) {
			if(macode==0)cout<<"L\n";
			else cout<<"2\n";
		}
	}
	if(macode==0)cout<<'#';
	else cout<<"-1\n";
	return 0;
}
