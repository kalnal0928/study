# -*- coding: utf-8 -*-
import sys
import io

# 표준 출력 인코딩을 UTF-8로 설정
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

katok = ["다현", "정연", "채영", "사나", "모모", "지효", "쯔위", "나연", "미나"]
katok.append("예지")    

katok.append(None)

print(katok)