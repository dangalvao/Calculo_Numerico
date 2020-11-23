def f(x):
  return x

def diferenca_dividida(lista_x):
  k = len(lista_x)
  if k == 1:
    return f(lista_x[0])
  else:
    print((diferenca_dividida(lista_x[1:])-diferenca_dividida(lista_x[:k-1]))/(lista_x[-1]-lista_x[0]))
    return (diferenca_dividida(lista_x[1:])-diferenca_dividida(lista_x[:k-1]))/(lista_x[-1]-lista_x[0])

lista1 = {
  "x": [0,2,4,7],
  "y": [1,3,-1,4]
}
print(diferenca_dividida(lista1["x"]))