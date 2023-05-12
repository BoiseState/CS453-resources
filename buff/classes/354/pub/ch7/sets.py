#!/usr/bin/python

s1=set(["a","b","c"])
s2=set(["c","d","e"])
s3=s1|s2                        # S3 = {"a","b","c","d","e"}
s3=s1&s2                        # S3 = {"c"}
s3=s1-s2                        # S3 = {"a","b"}
s3=s1^s2                        # S3 = {"a","b","d","e"}

print s3
for v in s3:
    print v,

s1=set(["c","d","e"])
result=s1==s2                   # True
result=s1<s2                    # False
result=s1<=s2                   # True

s1=set(["c","d"])
result=s1!=s2                   # True
result=s2>s1                    # True
result=s2>=s1                   # True
