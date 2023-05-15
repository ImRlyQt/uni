from md5 import md5

input_string = input("Wpisz tekst do zhashowania: ")
hash_object = md5(input_string.encode())
print(hash_object.hex())
