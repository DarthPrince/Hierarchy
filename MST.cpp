#include <bits/stdc++.h>

using namespace std;

struct Invoice {

 string Invoice_Name;
 int Value;
 string Categorie;
  string date;
    string project;
    string country;
    int Time_process;
 };

struct Person {
    string Person_Name;
    int Accept_Time;
    int Nb_Ac;
    int Nb_invoices;
    vector <Invoice> invoices;
    int Nb_rules;

    vector<string>  project[2], category[2],country[2],date[2];
    vector<int> value[2];

    };



typedef pair<int, int> iPair;
# define INF 0x3f3f3f3f
int katyouchka[1001];
void primMST(vector<pair<int,int> > adj[], int V)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    int src = 0;
    vector<int> key(V, INF);

    vector<int> parent(V, -1);

    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;
        for (int yh=0;yh<adj[u].size();yh++)
        {
            pair<int,int> x=adj[u][yh];
            int v = x.first;
            int weight = x.second;


            if (inMST[v] == false && key[v] > weight)
            {

                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i)
      katyouchka[i]=parent[i];
}



string s;
int a,b,c,x;
int d;
string s1,s2,s3,s4,s5;
Person Employees[1001];
vector<string>::iterator it,it2,it1,it0,it3,it4;
vector<pair<int , string > >e;
int main()
{
      freopen ("TestHackathon-5.txt", "r", stdin);
      freopen ("my.txt","w",stdout);

     int n;

     cin>>n; cin.ignore();
     for (int i=0;i<n;i++)
     {
       cin>>s; cin.ignore();
       cin>>a; cin.ignore();
       cin>>b; cin.ignore();
       cin>>c; cin.ignore();
       Employees[i].Person_Name=s;
       Employees[i].Accept_Time=a;
       Employees[i].Nb_Ac=b;
       Employees[i].Nb_invoices=c;


           for (int j=0;j<c;j++)
           {   cin>>s1; cin.ignore();
               cin>>d; cin.ignore();
               cin>>s2; cin.ignore();
               cin>>s3; cin.ignore();
               cin>>s4; cin.ignore();
               cin>>s5; cin.ignore();
               cin>>x; cin.ignore();

               Invoice rhouma;
               rhouma.Invoice_Name=s1;
               rhouma.Value=d;
               rhouma.Categorie=s2;
               rhouma.date=s3;
               rhouma.project=s4;
               rhouma.country=s5;
               rhouma.Time_process=x;
               Employees[i].invoices.push_back(rhouma);


           }


           cin>>a; cin.ignore();
           Employees[i].Nb_rules=a;
           string line;

           for (int j=0;j<a;j++)
           {   string sep="";

                int comp=0;
                bool nm=false;
                bool ex=false;
                getline(cin,line);
                string rule="";

                int in=2;

                for (int k=0;k<line.size();k++)
                {  if (line[k]==' ') {  if ( nm==false) {

                     rule=sep;sep=""; comp++;nm=true;}
                                        else if (ex==false) {

                                        if(sep=="Exclude")in=1;else in=0;sep=""; comp++;ex=true;}
                                         else {


                                        if( !rule.compare("Project"))
                                           {Employees[i].project[in].push_back(sep);


                                           }
                                        else if(rule=="Category")
                                        {
                                            Employees[i].category[in].push_back(sep);
                                        }
                                        else if(rule=="Country")
                                        {
                                            Employees[i].country[in].push_back(sep);
                                        }
                                        else if(rule=="Value")
                                        {   // cout<<atoi(sep.c_str())<<"ffgfg"<<endl;
                                            Employees[i].value[in].push_back(atoi(sep.c_str()));
                                        }
                                        else if(rule!="")Employees[i].date[in].push_back(sep);
                                        sep=""; comp++;

                                                                   }}
                   else sep+=line[k];

                }


           }

     }
     vector<pair<int,int> > vv[1001];
     for(int i=0;i<n;i++)
        for(int k=i+1;k<n;k++)
     {
         if(k==i) continue;
         int l=Employees[k].Nb_invoices;

         for(int j=0;j<l;j++)
         {
             it = find (Employees[i].project[0].begin(), Employees[i].project[0].end(),Employees[k].invoices[j].project );
             it2 = find (Employees[i].project[1].begin(), Employees[i].project[1].end(),Employees[k].invoices[j].project );

             it1 = find (Employees[i].category[0].begin(), Employees[i].category[0].end(),Employees[k].invoices[j].Categorie );
             it0 = find (Employees[i].category[1].begin(), Employees[i].category[1].end(),Employees[k].invoices[j].Categorie );

             it3 = find (Employees[i].country[0].begin(), Employees[i].country[0].end(),Employees[k].invoices[j].country );
             it4 = find (Employees[i].country[1].begin(), Employees[i].country[1].end(),Employees[k].invoices[j].country );



             if (((it != Employees[i].project[0].end())||(it2 == Employees[i].project[1].end()))&&
                 ((it1!= Employees[i].category[0].end())||(it0 == Employees[i].category[1].end()))&&
                ((it != Employees[i].country[0].end())||(it2 == Employees[i].country[1].end()))  )
                {


bool inc=true,exc=true;

             if(Employees[i].value[0].size()>1) { inc=false;

                    if((Employees[k].invoices[j].Value<=Employees[i].value[0][1])&&(Employees[k].invoices[j].Value>=Employees[i].value[0][0]))
                    {
                        bool inc=true;
                    }

             }
             if(Employees[i].value[1].size()>1)
             {
                 exc=false;
                 if((Employees[k].invoices[j].Value>Employees[i].value[0][1])&&(Employees[k].invoices[j].Value<Employees[i].value[0][0]))
                    {
                        bool exc=true;
                    }
             }
             if(exc&&inc)
             e.push_back(make_pair(Employees[k].invoices[j].Time_process,Employees[k].invoices[j].Invoice_Name));
         }
         }
         sort(e.begin(),e.end());
         vector<string> lina;
         int y=0;
         int dd=0;
         for(int h=0;h<e.size();h++)
         {
             if(y==Employees[i].Nb_Ac) break;
             else
             {dd+=e[h].first;
             if(dd>Employees[i].Accept_Time) break;
             else {lina.push_back(e[h].second);y++;}
             }
         }
         vv[i].push_back({k,-(int)lina.size()});
        lina.clear();
         e.clear();


     }
      int root;
    for(int i=0;i<n;i++)
    {
        if(vv[i].size()!=0) {root=i;break;}
    }

     for(int o=0;o<n;o++)
     {
         if((vv[o].size()==0))
         vv[o].push_back(make_pair(root,0));
     }
     root=0;





    primMST(vv,n);


 root=0;
      cout<<Employees[root].Person_Name<<" -"<<endl;
   cout<<Employees[root].Nb_invoices<<endl;
   for(int i=0;i<Employees[root].Nb_invoices;i++)
   {
      cout<<Employees[root].invoices[i].Invoice_Name<<" ";
   }
   cout<<endl;

     for (int i=1;i<n;i++)
     {

        cout<<Employees[i].Person_Name<<" "<<Employees[katyouchka[i]].Person_Name<<endl;
         int l=Employees[i].Nb_invoices;
cout<<l<<endl;

if(l)
             {for(int j=0;j<l;j++)
         {
               cout<<Employees[i].invoices[j].Invoice_Name<<" ";
         }

         cout<<endl;}
      }
     }

