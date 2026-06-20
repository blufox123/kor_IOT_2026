# Arduino UNO R4 — FND 스톱워치 배선도

4자리 7세그먼트(FND) 다이내믹 스캔 + 스위치 2개(시작/멈춤, 리셋)를 외부 인터럽트로 처리하는 회로의 전체 배선 블록도입니다.

## 전체 배선 블록도

<svg width="100%" viewBox="0 0 680 490" xmlns="http://www.w3.org/2000/svg" role="img" aria-label="아두이노 FND 스톱워치 전체 배선 블록도">
  <style>
    .t  { font-family: sans-serif; font-size: 14px; }
    .ts { font-family: sans-serif; font-size: 12px; }
    .th { font-family: sans-serif; font-size: 14px; font-weight: 500; }
    .blue   { fill: #E6F1FB; stroke: #185FA5; }
    .teal   { fill: #E1F5EE; stroke: #0F6E56; }
    .purple { fill: #EEEDFE; stroke: #534AB7; }
    .amber  { fill: #FAEEDA; stroke: #854F0B; }
    .coral  { fill: #FAECE7; stroke: #993C1D; }
    .gray   { fill: #F1EFE8; stroke: #5F5E5A; }
    .green  { fill: #EAF3DE; stroke: #3B6D11; }
    .tx-blue   { fill: #0C447C; }
    .tx-teal   { fill: #085041; }
    .tx-purple { fill: #3C3489; }
    .tx-amber  { fill: #633806; }
    .tx-coral  { fill: #712B13; }
    .tx-gray   { fill: #444441; }
    .tx-green  { fill: #27500A; }
    .wire { fill: none; stroke: #73726c; stroke-width: 1.5; }
  </style>
  <defs>
    <marker id="arrow" viewBox="0 0 10 10" refX="8" refY="5" markerWidth="6" markerHeight="6" orient="auto-start-reverse">
      <path d="M2 1L8 5L2 9" fill="none" stroke="#73726c" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"/>
    </marker>
  </defs>

  <rect class="blue" x="40" y="44" width="180" height="288" rx="16" stroke-width="0.5"/>
  <text class="th tx-blue" x="130" y="70" text-anchor="middle">Arduino UNO R4</text>
  <text class="ts tx-blue" x="130" y="88" text-anchor="middle">RA4M1</text>

  <rect class="teal" x="58" y="102" width="144" height="62" rx="10" stroke-width="0.5"/>
  <text class="th tx-teal" x="130" y="128" text-anchor="middle">세그먼트 출력</text>
  <text class="ts tx-teal" x="130" y="148" text-anchor="middle">D4 ~ D11</text>

  <rect class="teal" x="58" y="172" width="144" height="62" rx="10" stroke-width="0.5"/>
  <text class="th tx-teal" x="130" y="198" text-anchor="middle">자리 선택</text>
  <text class="ts tx-teal" x="130" y="218" text-anchor="middle">D14 ~ D17 (A0~A3)</text>

  <rect class="purple" x="58" y="242" width="144" height="62" rx="10" stroke-width="0.5"/>
  <text class="th tx-purple" x="130" y="268" text-anchor="middle">인터럽트 입력</text>
  <text class="ts tx-purple" x="130" y="288" text-anchor="middle">D2, D3 · PULLUP</text>

  <rect class="amber" x="460" y="44" width="180" height="200" rx="16" stroke-width="0.5"/>
  <text class="th tx-amber" x="550" y="70" text-anchor="middle">4자리 7세그먼트</text>
  <text class="ts tx-amber" x="550" y="88" text-anchor="middle">공통 양극</text>

  <rect class="coral" x="478" y="102" width="144" height="58" rx="10" stroke-width="0.5"/>
  <text class="th tx-coral" x="550" y="126" text-anchor="middle">세그먼트 a ~ dp</text>
  <text class="ts tx-coral" x="550" y="144" text-anchor="middle">LOW = 점등</text>

  <rect class="coral" x="478" y="172" width="144" height="58" rx="10" stroke-width="0.5"/>
  <text class="th tx-coral" x="550" y="196" text-anchor="middle">공통 D1 ~ D4</text>
  <text class="ts tx-coral" x="550" y="214" text-anchor="middle">HIGH = 선택</text>

  <rect class="gray" x="300" y="115" width="100" height="36" rx="6" stroke-width="0.5"/>
  <text class="th tx-gray" x="350" y="129" text-anchor="middle" dominant-baseline="central">저항 ×8</text>
  <text class="ts tx-gray" x="350" y="143" text-anchor="middle" dominant-baseline="central">220~330Ω</text>
  <line class="wire" x1="202" y1="133" x2="298" y2="133" marker-end="url(#arrow)"/>
  <line class="wire" x1="400" y1="133" x2="460" y2="133" marker-end="url(#arrow)"/>

  <rect class="gray" x="300" y="185" width="100" height="36" rx="6" stroke-width="0.5"/>
  <text class="th tx-gray" x="350" y="199" text-anchor="middle" dominant-baseline="central">트랜지스터 ×4</text>
  <text class="ts tx-gray" x="350" y="213" text-anchor="middle" dominant-baseline="central">(권장)</text>
  <line class="wire" x1="202" y1="203" x2="298" y2="203" marker-end="url(#arrow)"/>
  <line class="wire" x1="400" y1="203" x2="460" y2="203" marker-end="url(#arrow)"/>

  <rect x="40" y="360" width="400" height="108" rx="12" fill="none" stroke="#73726c" stroke-width="0.5" stroke-dasharray="4 4"/>
  <text class="ts tx-gray" x="58" y="382">스위치 입력부 — 버튼 한쪽 핀, 반대쪽 GND</text>

  <rect class="green" x="62" y="396" width="168" height="56" rx="10" stroke-width="0.5"/>
  <text class="th tx-green" x="146" y="420" text-anchor="middle">SW1 · 시작/멈춤</text>
  <text class="ts tx-green" x="146" y="440" text-anchor="middle">D2 ↔ GND</text>

  <rect class="green" x="250" y="396" width="168" height="56" rx="10" stroke-width="0.5"/>
  <text class="th tx-green" x="334" y="420" text-anchor="middle">SW2 · 리셋</text>
  <text class="ts tx-green" x="334" y="440" text-anchor="middle">D3 ↔ GND</text>

  <line class="wire" x1="130" y1="304" x2="130" y2="358" marker-end="url(#arrow)"/>
</svg>

## 핀 배치표

| 아두이노 핀 | 연결 대상 | 비고 |
|---|---|---|
| D2 | SW1 (시작/멈춤) | 반대쪽 → GND, INPUT_PULLUP, FALLING |
| D3 | SW2 (리셋) | 반대쪽 → GND, INPUT_PULLUP, FALLING |
| D4 | 세그먼트 a | 저항 직렬 |
| D5 | 세그먼트 b | 저항 직렬 |
| D6 | 세그먼트 c | 저항 직렬 |
| D7 | 세그먼트 d | 저항 직렬 |
| D8 | 세그먼트 e | 저항 직렬 |
| D9 | 세그먼트 f | 저항 직렬 |
| D10 | 세그먼트 g | 저항 직렬 |
| D11 | 세그먼트 dp | 저항 직렬 |
| D14 (A0) | 자리 공통 D1 | 트랜지스터 경유 권장 |
| D15 (A1) | 자리 공통 D2 | 트랜지스터 경유 권장 |
| D16 (A2) | 자리 공통 D3 | 트랜지스터 경유 권장 |
| D17 (A3) | 자리 공통 D4 | 트랜지스터 경유 권장 |

## 배선 시 확인 사항

- **스위치 배선 방향**: 버튼 한쪽은 핀(D2 또는 D3), 반대쪽은 반드시 GND로 연결합니다. 이 구조라야 `INPUT_PULLUP` + `FALLING` 조합이 맞습니다(평소 HIGH, 누르면 LOW로 하강). 버튼을 전원(5V/3.3V) 쪽으로 연결하면 로직이 반대가 되어 인터럽트가 잡히지 않습니다.
- **FND 극성**: 코드는 공통 양극(Common Anode) 기준입니다. 부품이 공통 음극이면 세그먼트 점등 로직과 자리 선택 로직이 모두 반대라 화면이 깨집니다. 데이터시트로 극성을 먼저 확인하세요.
- **자리 핀 트랜지스터**: 한 자리에 세그먼트 8개가 동시에 켜지면 전류가 자리 핀 하나로 몰려 MCU 핀 허용치를 넘을 수 있습니다. 공통 양극이면 PNP 트랜지스터(또는 P-ch MOSFET)로 받아주는 것이 안전합니다.
- **세그먼트 저항**: 각 세그먼트 라인(D4~D11)에 220~330Ω 정도의 전류 제한 저항을 직렬로 넣습니다.
