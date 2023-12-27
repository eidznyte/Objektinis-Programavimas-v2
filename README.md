# Objektinis-programavimas
## Programos aprašymas
Šiame release programoje atsirado įvesties ir išvesties operatoriai _operator>>_ ir _operator<<_.
Taip pat realizuota "rule of three"
* _operator>>_ perskaito duomenis į "Student" objektą.
* _operator<<_ surašo duomenis iš "Student" objekto.
### "rule of three" implementacija
* Kopijavimo konstruktorius – sukuria naują "Student" objektą kaip esamo kopiją.
* Priskirimo operatorius – priskiria vieną "Student" objektą kitam.
* Destruktorius – sunaikina "Student" objektą, išskleisdamas jo duomenis.
## Programos naudojimas
### Programos paleidimas:
* Programą paleisti per kodo editinimo programą (pvz. VisualStudio)
## Programos Struktūra:
* Main1.1.cpp -> pagrindinis file
* Students1.1.cpp -> visų funkcijų file
* Students.h -> header file
* students.txt -> duomenų file, kuriuo naudojamasi programoje
## Ką daro ši programa?
* Sugeneruoja atsitiktinius duomenis
* Gali nuskaityti duomenis iš failo
* Duomenis gali įvesti pats vartotojas
* Matuoja funkcijų veikimo laikus
* Surūšiuoja duomenys i dvi kategorijas: "Smart" ir "Dummies"
* Gautus rezultatus pateikia lentelėje tekstiniame faile
* Gali apskaičiuoti tiek medianą, tiek vidurkį
