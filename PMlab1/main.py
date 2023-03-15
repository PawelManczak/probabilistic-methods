
def variations_without_repetitions(alphabet, n, result, curr):
    if n == 0:
        result.append(curr)
        return

    for i in range(len(alphabet)):
        if curr[len(curr) - 1] >= alphabet[i]:
            continue
        variations_without_repetitions(alphabet, n - 1, result, curr + alphabet[i])

if __name__ == '__main__':
    alphabet = ['1', '2', '3', '4', '5']
    result = []
    variations_without_repetitions(alphabet, 2, result, " ");

    print(result)
