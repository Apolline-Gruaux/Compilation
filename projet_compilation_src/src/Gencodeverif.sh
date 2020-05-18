#!/usr/bin/env bash
# Tests de syntaxe
#
#cat minictest.c | while read line; do
    #echo $line
#done

cd Tests/Syntaxe/OK

#if [[ -e "$PWD/Tests/Gencode/KO/minicctest_gencodeko.mc" ]]; then
#  echo "file exists"
#fi
declare -a tableau_indi=("minictest0.c" "minictest1.c" "minictest2.c" "minictest3.c")
declare -a tab_carac=("s/==/!=/g" "s/var1/carotte/g" "s/if/while/g" "s/true/false/g")
#fichier de reference : minictestVerif.c
echo "void main() {" > minictestVerif.c
echo "	int var1 = 0 ;" >> minictestVerif.c
echo "	bool var2 = true;" >> minictestVerif.c
echo "	if (var2 == true) {" >> minictestVerif.c
echo "	  var1 = 1;" >> minictestVerif.c
echo "	}" >> minictestVerif.c
echo "	print(var1);">> minictestVerif.c
echo "}" >> minictestVerif.c
more minictestVerif.c
declare -i i=0
#sed -i '1 i\texte' minictestVerif.c #ajouter texte au dessus de ligne 1
more minictestVerif.c
while [ $i -lt 4 ]
do
    	# step 0
		cp --copy-contents minictestVerif.c ${tableau_indi[$i]}
        #sed -n 2p minictestVerif.c > minictest0.c
        #more minictest0.c
        echo "minic test 0"
        echo ${tableau_indi[$i]}
        sed -i ${tab_carac[$i]} ${tableau_indi[$i]}
        more ${tableau_indi[$i]}

		i=$[$i+1]
done
cd ../KO

# Tests de verification
cd ../../Verif/OK



cd ../KO

# Test de Gencode
cd ../../Gencode/KO

cd ../OK
cd ../../..
declare -i i=0
echo "Compilation des fichiers de verification OK"
while [ $i -lt 4 ]
do
        echo "**********************************************************"
		echo ${tableau_indi[$i]}
        ./minicc Tests/Syntaxe/OK/${tableau_indi[$i]}

		i=$[$i+1]
done
