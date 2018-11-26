function reset(){location.reload();}

var primerNodo=document.getElementById('first');
var finalNodo=document.getElementById('last');

function seleccion(nodo){
  if(primerNodo.innerHTML=='First'){
    var nodoSelect=document.getElementById(nodo);
      nodoSelect.style.background="purple";
      primerNodo.innerHTML=nodoSelect.id;
  }
  else if(finalNodo.innerHTML=='Last'){
    var nodoSelect2=document.getElementById(nodo);
      nodoSelect2.style.background="purple";
      finalNodo.innerHTML=nodoSelect2.id;
  }
}
