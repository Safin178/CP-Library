bool is_vowel(char ch) { 
  string s = "aeiouAEIOU"; 
  for (int i = 0; s[i]; i++) { 
    if (s[i] == ch) { 
      return 1; 
    } 
  } 
  return 0; 
} 