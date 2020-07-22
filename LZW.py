def encode(uncompressed):
    dict_size = 256 #Xây dựng từ điển
    dictionary = dict((chr(i), i) for i in range(dict_size))
    w = ""
    result = []
    for c in uncompressed:
        wc = w + c
        if wc in dictionary:
            w = wc
        else:
            result.append(dictionary[w])
            dictionary[wc] = dict_size #Thêm WC vào trong từ điểm
            dict_size += 1
            w = c
    if w:
        result.append(dictionary[w])
    return result
 
 
def decode(compressed):
    from io import StringIO
    dict_size = 256
    dictionary = dict((i, chr(i)) for i in range(dict_size))
    result = StringIO()
    w = chr(compressed.pop(0))
    result.write(w)
    for k in compressed:
        if k in dictionary:
            entry = dictionary[k]
        elif k == dict_size:
            entry = w + w[0]
        else:
            raise ValueError('Bad compressed k: %s' % k)
        result.write(entry)
 
        dictionary[dict_size] = w + entry[0]
        dict_size += 1
 
        w = entry
    return result.getvalue()
 
if __name__ == "__main__":
    s = input()
    compressed = encode(s)
    print (compressed)
    decompressed = decode(compressed)
    print (decompressed)