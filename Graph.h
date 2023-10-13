#ifndef MAXV
#define MAXV 1000
#endif

#include <iostream>
#include <cstdlib>
using namespace std;
 
class Graph
{
    private:
    	
		struct SlogCvor {
		    int oznaka;
		    struct SlogCvor* sljedeci;
		};
		 
		
		struct SlogListaSusjd {
		    struct SlogCvor *glavaL;
		};
		
	    	
	    SlogListaSusjd* polje; 
        
    public:
    	
        Graph() {
            polje = new SlogListaSusjd[MAXV];		
            for (int i = 0; i < MAXV; ++i)
                polje[i].glavaL = NULL;  	
        }

        void addEdge(int izvor, int odrediste) {
			if(izvor > MAXV || odrediste > MAXV){
				cout << "Oznaka cvora premasuje maksimalnu vrijednost." << endl ;
				exit(EXIT_FAILURE);
			}else{
				
	    	
	        	SlogCvor* noviCvor = new SlogCvor;  
	            noviCvor->oznaka = odrediste;			
	            noviCvor->sljedeci = NULL;	
	            									
	            noviCvor->sljedeci = polje[izvor].glavaL;	
	            polje[izvor].glavaL = noviCvor;			
	            
	            
				noviCvor = new SlogCvor; 			
	            noviCvor->oznaka = izvor;				
	            noviCvor->sljedeci = NULL;			
	
	            noviCvor->sljedeci = polje[odrediste].glavaL;
	            polje[odrediste].glavaL = noviCvor;		
        	}
        }
        
        void printGraph(){
        	
            for (int i = 0; i < MAXV; ++i) {
                
                if(isVertex(i)){
                	
             	    SlogCvor* priv = polje[i].glavaL;		
               		cout<<"\nCvorovi povezani sa cvorom "<<i<<": \n";
               		
	                while (priv) {
	                	
	                	cout<<priv->oznaka;
	                	if(priv->sljedeci != NULL){
	                   		cout<< ", ";
						}
						
	                    priv = priv->sljedeci;
	                }
	                
	                cout<<endl;
				}
            }
        }
        
        bool isVertex(int vertKey){
        	if(vertKey > MAXV){
				cout << "Oznaka cvora premasuje maksimalnu vrijednost." << endl;
				exit(EXIT_FAILURE);
			}else{
				
        		return polje[vertKey].glavaL;
        	}
		}
		
		bool isEdge(int fromVert, int toVert){
        	if((fromVert > MAXV) || (toVert > MAXV)){
				cout << "Oznaka cvora premasuje maksimalnu vrijednost." << endl ;
				exit(EXIT_FAILURE);
				
			}else{
				SlogCvor* priv = polje[fromVert].glavaL;
           		
                while (priv) {
                	
                	if(priv->oznaka == toVert){
                   		return true;
					}
					
                    priv = priv->sljedeci;
                }
                
                return false;
			}
		}
		
		
		void deleteEdge(int fromVert, int toVert){
			
			if((fromVert > MAXV) || (toVert > MAXV)){
				cout << "Oznaka cvora premasuje maksimalnu vrijednost." << endl ;
				exit(EXIT_FAILURE);
				
			}else{
				
				if(isVertex(fromVert) && isVertex(toVert)){
					
					
					// brisanje zapisa odredista iz liste izvora:
					SlogCvor* prethodni =  polje[fromVert].glavaL;
					if(prethodni->sljedeci == NULL){
						if(prethodni->oznaka == toVert){
						
							delete prethodni;
							
							polje[fromVert].glavaL = NULL;
							
						} else{
							cout << "Brid ("<< fromVert << ", " << toVert << ") ne postoji." <<  endl;
							exit(EXIT_FAILURE);
						}
			
					} else {
					
						if(prethodni->oznaka == toVert){
						
							polje[fromVert].glavaL = prethodni->sljedeci;
							delete prethodni;
							
							
						} else{
						
							SlogCvor* tekuci = (*prethodni).sljedeci;
							
							while (tekuci){
								if (tekuci->oznaka == toVert){
						    		prethodni->sljedeci = tekuci->sljedeci;
									delete tekuci;
									return;
						    	}
						    	
						    	prethodni = tekuci;
						    	tekuci = tekuci->sljedeci;
							}
						}
					
					}	
						
						
					// brisanje zapisa odredista iz liste izvora:
					SlogCvor* prthodni =  polje[toVert].glavaL;
					if(prthodni->sljedeci == NULL){
						if(prthodni->oznaka == fromVert){
						
							delete prthodni;
							
							polje[toVert].glavaL = NULL;
							
						} else{
							cout << "Brid ("<< toVert << ", " << fromVert << ") ne postoji." <<  endl;
							exit(EXIT_FAILURE);
						}
			
					} else {
					
						if(prthodni->oznaka == fromVert){
						
							polje[toVert].glavaL = prthodni->sljedeci;
							delete prthodni;
							
							
						} else{
						
							SlogCvor* tekuci = (*prthodni).sljedeci;
							
							while (tekuci){
								if (tekuci->oznaka == fromVert){
						    		prthodni->sljedeci = tekuci->sljedeci;
									delete tekuci;
									return;
						    	}
						    	
						    	prthodni = tekuci;
						    	tekuci = tekuci->sljedeci;
							}
						}
					
					}	
				
				}
			
			}
		}
		
		
		~Graph(){
			for(int i=0; i<MAXV; i++){	
				SlogCvor* L =  polje[i].glavaL;
				while(L != NULL){
					
					SlogCvor* p = L;
					L = (*L).sljedeci;
					delete p;
					
				}
			}
		}
		
		
};
 
