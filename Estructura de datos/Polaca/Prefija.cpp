/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-4-Estructura-de-datos-7999
 *********/
#include "Prefija.h"

using namespace std;

int Pre::getPosi()
{
	return posi;
}

string* Pre::inAPre(string infija)
{
	
	reverse(infija.begin(),infija.end());
	string elem ="";string numeri = "";
	posi=0;
	
	
	for(int i=0;i<=infija.size();i++)
	{
		char e = infija[i];
		string d;
		d.push_back(e);
		
		if(d==")")
		{
			pila.push(d);
		}
		else if(d=="+"||d=="-"||d=="*"||d=="/"||d=="^")
		{	
			if(elem!="")
				{
					reverse(elem.begin(),elem.end());
					opera[posi] = elem; posi++;
					elem="";
				}
			opera[posi] = " "; posi++;
			while(!pila.getPilaVacia() && pila.getPrimero()->getValor()!=")" && priorizar(d)<=priorizar(pila.getPrimero()->getValor()))
			{
				opera[posi]=pila.getPrimero()->getValor(); posi++;
				opera[posi] = " "; posi++;
				pila.pop();
			}
			pila.push(d);
		}
		else if((d>="0" && d<="9")|| d==".")
		{
			elem+=d;
		}
		else if(e>=97 && e<=122)
		{
			numeri+=d;
			
			if(numeri=="trqs"||numeri=="nis"||numeri=="soc"||numeri=="nat"||numeri=="niscra"||numeri=="soccra"||numeri=="natcra"||numeri=="hnes"||numeri=="hsc"||numeri=="hgt")
			{
				reverse(numeri.begin(),numeri.end());
				
				if(elem!="")
				{
					reverse(elem.begin(),elem.end());
					opera[posi] = elem; posi++;
					elem="";
				}
			
				while(!pila.getPilaVacia() && pila.getPrimero()->getValor()!=")" && priorizar(numeri)<=priorizar(pila.getPrimero()->getValor()))
				{
					opera[posi]=pila.getPrimero()->getValor();posi++;
					opera[posi]=" "; posi++;
					pila.pop();
				}
				pila.push(numeri);
				numeri="";
			}
			
			if(numeri=="ip"||numeri=="e")
			{
				
				if(elem!="")
				{
					reverse(elem.begin(),elem.end());
					opera[posi] = elem; posi++;
					elem="";
				}
			
				opera[posi] = " "; posi++;
				elem+=numeri;
				
				numeri="";
				
			}
			
		}
		else if(d=="(")
		{
			bool paren = false;
		
			if(elem!="")
				{
					reverse(elem.begin(),elem.end());
					opera[posi] = elem; posi++;
					elem="";
				}
			
			Nodo *piloso = pila.getPrimero();
			string op = piloso->getValor();
			while(piloso!=NULL&&paren!=true)
			{
				opera[posi] = " ";posi++;
			
				if(piloso->getValor()!=")")
				{
					opera[posi]=piloso->getValor();posi++;
					opera[posi] =" ";
				}
				else if(piloso->getValor()==")" && paren==false)
				{
					paren=true;
				}
				else
				{
					paren=false;
					break;
				}
				pila.pop();
				piloso = pila.getPrimero();
				
			}
		}
		
	}
	if(elem!="")
	{
		reverse(elem.begin(),elem.end());
		opera[posi] = elem; posi++;
		elem="";
	}			
	opera[posi] = " ";posi++;
	
	Nodo *piloso2 = pila.getPrimero();
		while(piloso2!=NULL)
		{	
			if(piloso2->getValor()!=")")
			{
				opera[posi]=piloso2->getValor();posi++;
				opera[posi] = " ";posi;
			}
			
			pila.pop();
			piloso2 = pila.getPrimero();
		}
		
		int aux = posi;
		
		for(int x =0;x<=aux;x++,aux--)
		{
			string temp = opera[x];
			opera[x] = opera[aux];
			opera[aux] = temp;
		}
		
		                
	return opera;
}

float Pre::resuelve(string opi)
{
		float resul = 0;
		float a, b;
	for(int i=posi;i>=0;i--)
	{
		if(opera[i]!=" ")
		{
		
			if(opera[i]=="+")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rs = suma(a,b);
				pila.push(to_string(rs));
			
			}
		
			else if(opera[i]=="-")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rr = resta(a,b);
				pila.push(to_string(rr));

			}
		
			else if(opera[i]=="*")
			{
				a =  stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rm = multi(a,b);
				pila.push(to_string(rm));

			}
		
			else if(opera[i]=="/")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rd = divi(a,b);
				pila.push(to_string(rd));
				
			}
		
			else if(opera[i]=="^")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				b = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rp = pot(a,b);
				pila.push(to_string(rp));
			
			}
		
			else if(opera[i]=="sqrt")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rra = raiz(a);
				pila.push(to_string(rra));
			
			}
			else if(opera[i]=="sin")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rsin = sen(a);
				pila.push(to_string(rsin));
			}
			else if(opera[i]=="cos")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rcos = cose(a);
				pila.push(to_string(rcos));
			}
			else if(opera[i]=="tan")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rtan = tange(a);
				pila.push(to_string(rtan));
			}
			else if(opera[i]=="arcsin")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rasin = arcsen(a);
				pila.push(to_string(rasin));
			}
			else if(opera[i]=="arccos")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float racos = arccose(a);
				pila.push(to_string(racos));
			}
			else if(opera[i]=="arctan")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float ratan = arctange(a);
				pila.push(to_string(ratan));
			}
			else if(opera[i]=="senh")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rsinh = senh(a);
				pila.push(to_string(rsinh));
			}
			else if(opera[i]=="csh")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rcosh = coseh(a);
				pila.push(to_string(rcosh));
			}
			else if(opera[i]=="tgh")
			{
				a = stof(pila.getPrimero()->getValor());
				pila.pop();
				float rtanh = tangeh(a);
				pila.push(to_string(rtanh));
			}
			
			else
			{
				
				if(opera[i]=="pi")
				{
					pila.push(to_string(M_PI));
				}
				else if(opera[i]=="e")
				{
					pila.push(to_string(M_E));
				}else
				{
					pila.push(opera[i]);
				}
		
			}
	
		}
	}
	
	resul = stof(pila.getPrimero()->getValor());
	
	return resul;
}



float Pre::suma(float a,float b)
{
	return a+b;
}
float Pre::resta(float a,float b)
{
	return a-b;
}
float Pre::multi(float a,float b)
{
	return a*b;
}
float Pre::divi(float a,float b)
{
	return a/b;
}
float Pre::pot(float a, float b)
{
	return pow(b,a);
}
float Pre::raiz(float a)
{
	return sqrt((double)a);
}
float Pre::sen(float a)
{
	return sin((double)a);
}
float Pre::cose(float a)
{
	return cos((double)a);
}
float Pre::tange(float a)
{
	return tan((double)a);
}
float Pre::arcsen(float a)
{
	return asin((double) a);
}
float Pre::arccose(float a)
{
	return acos((double)a);
}
float Pre::arctange(float a)
{
	return atan((double)a);
}
float Pre::senh(float a)
{
	return sinh((double)a);
}
float Pre::coseh(float a)
{
	return cosh((double)a);
}
float Pre::tangeh(float a)
{
	return tanh((double)a);
}


int Pre::priorizar(string c)
{
	if(c=="+"||c=="-")
	{
		return 1;
	}
	else if(c=="*"||c=="/")
	{
		return 2;
	}
	else if(c=="^"||c=="sqrt")
	{
		return 3;
	}
	else if(c=="sin"||c=="cos"||c=="tan"||c=="arcsin"||c=="arccos"||c=="arctan"||c=="senh"||c=="csh"||c=="tgh")
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

