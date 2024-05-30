

% -- Listas --

% num_elementos(+Lista, -Num)
% es cierto si Num unifica con el número de elementos de Lista

% Principio de Inducción:
% 	1) La propiedad tiene que ser cierta para N0, P(N0).
% 	2) La propiedad tiene que ser cierta para N > 1, N > N0, P(N-1) -> P(N)

% ¿Cuál es la lista más pequeña?
% La lista vacía []

% Solución de N0
num_elementos([], 0).

num_elementos([_|Resto], N2) :- num_elementos(Resto, N), N2 is N +1.
