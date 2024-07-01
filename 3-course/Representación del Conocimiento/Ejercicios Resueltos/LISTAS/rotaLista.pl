% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ------------- ROTA LISTA -------------
%
% Función -> rota(?L1, ?L2)
%
% ***|Se verifica si L2 unifica con la lista
% ***|L1 con el primer elemento en la última
% ***|posición
% ---------------------------------------

% Hallamos la solución
rota([Cab|Resto], LisR) :-
    append(Resto, [Cab], LisR).
