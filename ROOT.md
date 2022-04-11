# Operazioni tra istogrammi 
- Si possono fare solo tra istogrammi omologhi
- Si possono usare in overload (vale solo per le istanze, non per i puntatori)
```
TH1F h1;
TH1F h2=3*h1;
TH2F h3=h1+h2;
```
Oppure attraverso i metodi della classe (consigliato)
```
h->Add(...) // somma
h->Divide(...)// divisione
hRes->Add(h1, h2, ...)
```
### Il metodo Divide
``` 
virtual Bool_t Divide (const TH1 *h1, const TH1 *h2,
Double_t c1=1, Double_t c2=1, Option_t *option="") //this= c1*h1/c2*h2
```
### Il metodo Add
```
virtual Bool_t Add (const TH1 * h1, const TH1 *h2, Double_t c1=1, Double_t c2=1) // this= c1*h1+c2*h2 (per sottrarre due istogrammi mettere c2=-1)
```
Bisogna prima creare un istogramma extra che contenga l’esito della somma e della differenza. Fatelo con il Copy Constructor:
- Il **Copy Constructor** di TH1F: ``` TH1F::TH1F ( const TH1F & h1) ```

### Nel concreto:
```
//creazione dei due istogrammi
TH1F *h1 = new TH1F("h1","Tempi di Caduta 1",10,-0.5,19.5);
TH1F *h2 = new TH1F("h2","Tempi di Caduta 2",10,-0.5,19.5);
N.B. importante utilizzare metodo Sumw2() sugli istogrammi risultato del rapporto e divisione per avere incertezze corrette.
//....// cicli di lettura dati e riempimento istogrammi
//dopo averli riempiti confrontiamo i dati facendone il rapporto:
TH1F *hRatio=new TH1F(*h1);
hRatio->Divide(h1,h2,1,1);
//sommiamo i due campioni in un unico istogramma
TH1F *hSum=new TH1F(*h1); hSum->Add(h1,h2,1,1);
 (Macro maxwell-comb.C su Virtuale)
```
