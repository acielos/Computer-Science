% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ------ CONCATENA LISTAS ------
%
% Función -> conc(?L1, ?L2, ?L3)
%
% ***|Se verifica si L3 unifica con la lista L1
% ***|añadiéndole después los elementos de L2
%
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
conc([], L, L).

% Hallamos la recursividad
conc([Cab|Resto], L, [Cab|RestoI]) :-
    conc(Resto, L, RestoI).
