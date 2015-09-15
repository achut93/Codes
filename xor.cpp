#include <bits/stdc++.h>

using namespace std;
struct node
{
    node * first; node * second;
    node (node * a, node * b){first=a; second=b;}
};
node * root = new node (NULL, NULL);
void insert (node * x, string bits, int pos)
{
    if (pos==bits.length()) return;
    if (bits[pos]=='1')
    {
        if (x->second==NULL)
        {
            x->second=new node (NULL, NULL);
        }
        insert(x->second, bits, pos+1);
    }
    else
    {
        if (x->first==NULL)
        {
            x->first=new node (NULL, NULL);
        }
        insert(x->first, bits, pos+1);
    }
}
void query (node * t, string a, int pos, string & ans)
{
  if (pos==a.length()) return;
  if (a[pos]=='1')
  {
      if (t->first==NULL)
      {
          ans+="0"; query (t->second, a, pos+1, ans);
      }
      else
      {
          ans+="1"; query (t->first, a, pos+1, ans);
      }
  }
  else
  {
      if (t->second==NULL)
      {
          ans+="0"; query(t->first, a, pos+1, ans);
      }
      else
      {
          ans+="1"; query(t->second, a, pos+1, ans);
      }
  }
}
string conv (int a)
{
    string tor="";
    while (a)
    {
        if (a&1) tor='1'+tor;
        else tor='0'+tor;
        a/=2;
    }return tor;
}
int conv2 (string a)
{
    reverse(a.begin(), a.end());int answer=0;
    for (int g=0;g<a.length(); g++) {answer+=(a[g]-'0')*pow(2,g);}
    return answer;
}
int leftt[1000001];
int rightt[1000001];
int a[1000001];

int main()
{
	 int curxor=0, anss=0;
	 int b; scanf("%d", &b);
	 vector <string> t,rs;
	 int leng=0;
	 for (int y=0;y<b; y++)
	 {
		 int c;
		 scanf("%d", &c);
		 a[y] = c;
		 curxor^=c;
		 string store=conv(curxor);
		 t.push_back(store);
		 anss=max(anss, curxor);
		 leng=max(leng, (int)store.length());
	 }
	 curxor = 0;
	 anss = 0;
	 for(int i = t.size()-1;i>= 0;i--) {
		 curxor^=a[i];
		 string store=conv(curxor);
		 rs.push_back(store);
		 anss=max(anss, curxor);
	 }
	 anss = 0;
	 for (int g=0;g<t.size(); g++)
	 {
		 int r=t[g].length();
		 for (int y=0; y<leng-r; y++){
			 t[g]='0'+t[g];
		 }
		 r = rs[g].length();
		 for (int y=0; y<leng-r; y++){
					 rs[g]='0'+rs[g];
		}
	 }
	 for (int y=0;y<t.size(); y++)
	 {
		insert(root, t[y], 0); string ans="";
		query(root, t[y], 0, ans);
		anss=max(anss, conv2(ans));
		leftt[y]=max(leftt[y],anss);
	 }

	 root=new node (NULL, NULL);

	 for (int y=t.size()-1;y>=0; y--)
		 {
			insert(root, rs[y], 0); string ans="";
			query(root, rs[y], 0, ans);
			anss=max(anss, conv2(ans));
			rightt[y]=anss;
			rightt[y]=max(rightt[y],anss);
		 }

	 anss = 0;
	 for(int i = 0 ; i < t.size()-1 ; i++) {
		 if(leftt[i] + rightt[i+1] > anss){
			 //cout << i << "  " << leftt[i] << " " << rightt[i+1] << endl;
			 anss = leftt[i]+rightt[i+1];
		 }
	 }
	 cout << anss << endl;
	 return 0;
}
