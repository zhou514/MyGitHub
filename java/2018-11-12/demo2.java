// 2.字符串替换
// public String replaceAll(String regex,String replacement);  返回一个新字符串的内容是，将原字符串中符合regex的字符串都用replacement替换掉

String str = "12hello567bird".replaceAll("[a-zA-Z]+","你好");
//12你好567你好
