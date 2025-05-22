y;
    } else {  
        // The key is already in the table, so just replace the
        // current value with the new one.
        free(entry->value);  // Deallocate the current value
    }

    // Put the value associated with the key in the entry.
    entry->value = strdup(value);
    assert(entry->value != NULL);
}
/*Print the dictionary pointed to by dict, using the format:
0: key_0: value_0, key_1: value_1, ...
1: key_0: value_0, key_1: value_1, ...
...
n-1: key_0: value_0, key_1: value_1, ...
*/