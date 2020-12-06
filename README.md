***Anca-Maria CIUCIU***
***323 AB***
***Tema 1 POO***

Pentru executarea cerintelor: 

- s-a folosit o variabila **task** in care s-au citit valorile de 1 sau 0 ale cerintelor, urmand ca acestea sa fie rezolvate in functie de suma lor
> executabil:  *./lanparty c.in  d.in  r.out*
---
***TASK 1***

*Scop: formarea unei liste ce contine echipele de jucatori*

- se citesc echipele, respectiv jucatorii
- se verifica daca nu cumva numele echipelor contin spatii la finalul acestora, in caz afirmativ se elimina acele spatii
- toate aceste date se adauga intr-o lista dublu inlantuita cu ajutorul metodei **addTeam(Team team)**, membra a clasei **ListOfTeams**
	

---
***TASK 2*** 

*Scop: eliminarea echipelor cu cel mai mic punctaj*

- se afla numarul de stergeri din lista, care trebuie facute pentru a ajunge la un numar de echipe maxim egal cu o putere a lui 2
> nr_deletes = nr_echipe - closestPow2(nr_echipe);
- se parcurge lista de *nr_deletes* ori si se efectueaza eliminarea nodurilor cu ajutorul metodei **removeNodes()**
---


***TASK 3*** 

*Scop: simularea meciurilor dintre echipe*

- se afla numarul maxim de runde in care vor participa echipele
> numRounds = intlog(2, closestPow2(nr_echipe));
- se creaza coada de meciuri in care se adauga fiecare echipa in parte
- pentru realizarea duelurilor se extrag cate doua echipe din coada
- se compara scorurile celor doua echipe 
- se adauga *+1pt la scorul global* pentru echipa castigatoare
- echipa castigatoare va fi adaugata in stack-ul **winner** iar echipa care a pierdut va fi adaugata in stack-ul **loosers** care va fi sters ulterior
- din stiva de castigatori se vor extrage toate echipele si se vor pune la loc in coada de meciuri
- astfel, acest procedeu se va repeta pana cand va ramane o singura echipa in stack-ul winner - cea castigatoare
  


---

***TASK 4*** 

*Scop: clasamentul final al ultimelor 8 echipe*

- pentru realizarea acestei etape s-a folosit clasa **BST**
- se goleste stack-ul winner si se insereaza fiecare echipa in arborele binar cu ajutorul metodei **insert(Team team)**
- metoda **insert** analizeaza scorul global al echipelor, urmand ca acestea sa fie introduse in BST astfel incat sa se respecte structura clasica a unui arbore binar cat si exceptia egalitatii scorurilor
- in final, se foloseste o afisare de tip *right->print->left* pentru a se afla clasamentul ultimelor 8 echipe in ordine descrescatoare
  
---

**TASK 5**

*Scop: afisarea echipelor de pe nivelul 2 al arborelui AVL*

- pentru aceasta etapa a campionatului s-a folosit clasa **AVL**
- se utilizeaza arborele binar sortat de la etapa anterioara, aplicandu-se metoda createAVL(Node* nod, AVL* avl) pe root-ul deja instantiat
- inserarea nodurilor in AVL s-a realizat cu ajutorul metodei si a helper-ului cu acelasi nume dar cu parametri diferiti, **insert**, analizandu-se cele 4 tipuri de rotatii pentru a se pastra echilibrul arborelui

