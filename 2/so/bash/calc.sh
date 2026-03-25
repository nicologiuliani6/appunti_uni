#!/bin/sh
somma=$(expr $1 + $2)
echo "somma: $somma"
differenza=$(expr $1 - $2)
echo "differenza: $differenza"
prodotto=$(expr $1 \* $2)
echo "prodotto: $prodotto"
echo -n "A > B? "
if [ "$1" -gt "$2" ]; then 
  echo "true"
else 
  echo "false"
fi

