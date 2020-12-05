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

- se afla numarul de stergeri din lista care trebuie facute pentru a ajunge la un numar de echipe maxim egal cu o putere a lui 2
> nr_deletes = nr_echipe - closestPow2(nr_echipe);
- se parcurge lista de *nr_deletes* ori si se efectueaza eliminarea nodurilor cu ajutorul metodei **removeNodes()**
---


***TASK 3*** 

*Scop: simularea meciurilor dintre echipe*

- se afla numarul maxim de runde in care vor participa echipele
- se creaza coada de meciuri in care se adauga fiecare echipa in parte
- pentru realizarea duelurilor se extrag cate doua echipe din coada
- se compara scorurile celor doua echipe 
- se adauga +1pt la scorul global  


---



