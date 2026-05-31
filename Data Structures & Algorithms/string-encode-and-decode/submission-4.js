class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        // Encode as: length#string
        return strs.map(s => s.length + '#' + s).join('');
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        const res = [];
        let i = 0;

        while (i < str.length) {
            // Find the '#'
            let j = i;
            while (str[j] !== '#') {
                j++;
            }

            // Get the length before '#'
            const len = parseInt(str.slice(i, j));
            // Extract the string of given length
            const word = str.slice(j + 1, j + 1 + len);
            res.push(word);

            // Move pointer to next word
            i = j + 1 + len;
        }

        return res;
    }
}
