#include "Sogo_Draw.h"


void Sogo_Draw::InitScreen() // 게임 소개 화면
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                          ┃");
	ScreenPrint(0, 2, "┃                                                          ┃");
	ScreenPrint(0, 3, "┃                                                          ┃");
	ScreenPrint(0, 4, "┃                                                          ┃");
	ScreenPrint(0, 5, "┃                                                          ┃");
	ScreenPrint(0, 6, "┃                  ┏━━━━━━━━┓                    ┃");
	ScreenPrint(0, 7, "┃                  ┃★ Sogo(쏘고) ★┃                    ┃");
	ScreenPrint(0, 8, "┃                  ┗━━━━━┳━━┛                    ┃");
	ScreenPrint(0, 9, "┃                      /)/)    ┃ ☆                       ┃");
	ScreenPrint(0, 10, "┃                   ★(*'')/                               ┃");
	ScreenPrint(0, 11, "┃                                                          ┃");
	ScreenPrint(0, 12, "┃                                                          ┃");
	ScreenPrint(0, 13, "┃                                                          ┃");
	ScreenPrint(0, 14, "┃                                                          ┃");
	ScreenPrint(0, 15, "┃                                                          ┃");
	ScreenPrint(0, 16, "┃                                                          ┃");
	ScreenPrint(0, 17, "┃           ┏━━━┓★ 스페이스 키를 눌러 주세요!!       ┃");
	ScreenPrint(0, 18, "┃           ┃┃┃┃┣┓                                   ┃");
	ScreenPrint(0, 19, "┃           ┗┻┻┻┻┛                                   ┃");
	ScreenPrint(0, 20, "┃                                                          ┃");
	ScreenPrint(0, 21, "┃                                                          ┃");
	ScreenPrint(0, 22, "┃                                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void Sogo_Draw::ReadyScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                          ┃");
	ScreenPrint(0, 2, "┃                                                          ┃");
	ScreenPrint(0, 3, "┃                                                          ┃");
	ScreenPrint(0, 4, "┃                                                          ┃");
	ScreenPrint(0, 5, "┃                                                          ┃");
	ScreenPrint(0, 6, "┃                                                          ┃");
	ScreenPrint(0, 7, "┃                                                          ┃");
	ScreenPrint(0, 8, "┃                                          ●              ┃");
	ScreenPrint(0, 9, "┃                                    ☜〓━┃┑            ┃");
	ScreenPrint(0, 10, "┃                                        ☜〓┛            ┃");
	ScreenPrint(0, 11, "┃                                        ┏┻┓            ┃");
	ScreenPrint(0, 12, "┃                                                          ┃");
	ScreenPrint(0, 13, "┃                                                          ┃");
	ScreenPrint(0, 14, "┃                                                          ┃");
	ScreenPrint(0, 15, "┃                                                          ┃");
	ScreenPrint(0, 16, "┃                                                          ┃");
	ScreenPrint(0, 17, "┃                                                          ┃");
	ScreenPrint(0, 18, "┃                                                          ┃");
	ScreenPrint(0, 19, "┃                                                          ┃");
	ScreenPrint(0, 20, "┃                                                          ┃");
	ScreenPrint(0, 21, "┃                                                          ┃");
	ScreenPrint(0, 22, "┃                                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void Sogo_Draw::SuccessScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                          ┃");
	ScreenPrint(0, 2, "┃                                                          ┃");
	ScreenPrint(0, 3, "┃                                                          ┃");
	ScreenPrint(0, 4, "┃                                                          ┃");
	ScreenPrint(0, 5, "┃                                                          ┃");
	ScreenPrint(0, 6, "┃                       *.   .*                            ┃");
	ScreenPrint(0, 7, "┃                    *.┏┓┏┓.*대                        ┃");
	ScreenPrint(0, 8, "┃                    ┏┻┫┣┻┓단                        ┃");
	ScreenPrint(0, 9, "┃                    ┃━┫┣━┃해                        ┃");
	ScreenPrint(0, 10, "┃                    ┃━┫┣━┃요~                       ┃");
	ScreenPrint(0, 11, "┃                    ┗━┛┗━┛                          ┃");
	ScreenPrint(0, 12, "┃                                                          ┃");
	ScreenPrint(0, 13, "┃                                                          ┃");
	ScreenPrint(0, 14, "┃                      You Win!!                           ┃");
	ScreenPrint(0, 15, "┃                                                          ┃");
	ScreenPrint(0, 16, "┃                                                          ┃");
	ScreenPrint(0, 17, "┃                                                          ┃");
	ScreenPrint(0, 18, "┃                                                          ┃");
	ScreenPrint(0, 19, "┃                                                          ┃");
	ScreenPrint(0, 20, "┃                                                          ┃");
	ScreenPrint(0, 21, "┃                                                          ┃");
	ScreenPrint(0, 22, "┃                                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}
 

void Sogo_Draw::PlayerTalk()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                          ┃");
	ScreenPrint(0, 2, "┃                                                          ┃");
	ScreenPrint(0, 3, "┃                                                          ┃");
	ScreenPrint(0, 4, "┃                                       /| ━ // ━ |＼    ┃");
	ScreenPrint(0, 5, "┃                                      //q ●    ● p＼    ┃");
	ScreenPrint(0, 6, "┃                                        (┗┳━┳┛)      ┃");
	ScreenPrint(0, 7, "┃                                 우하하~   ┃ㅣ┃         ┃");
	ScreenPrint(0, 8, "┃                                           ┗━┛         ┃");
	ScreenPrint(0, 9, "┃           ┏┓━━━┏┓                                 ┃");
	ScreenPrint(0, 10, "┃           ┗┛ ┃ ┃┗┛                                 ┃");
	ScreenPrint(0, 11, "┃             ┃   ▽ ┃♡                                 ┃");
	ScreenPrint(0, 12, "┃              ━━━━                                    ┃");
	ScreenPrint(0, 13, "┃                                                          ┃");
	ScreenPrint(0, 14, "┃            :+:이번에는 너를 꼭 처단하리라:+:             ┃");
	ScreenPrint(0, 15, "┃                                                          ┃");
	ScreenPrint(0, 16, "┃                 :+: 받아라 나의 정의의 칼을  :+:         ┃");
	ScreenPrint(0, 17, "┃                                                          ┃");
	ScreenPrint(0, 18, "┃                                                          ┃");
	ScreenPrint(0, 19, "┃                                                          ┃");
	ScreenPrint(0, 20, "┃                                                          ┃");
	ScreenPrint(0, 21, "┃                                                          ┃");
	ScreenPrint(0, 22, "┃                                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void Sogo_Draw::BossTalk()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                          ┃");
	ScreenPrint(0, 2, "┃                                                          ┃");
	ScreenPrint(0, 3, "┃                                                          ┃");
	ScreenPrint(0, 4, "┃                                                          ┃");
	ScreenPrint(0, 5, "┃           ┏┓━━━┏┓                                 ┃");
	ScreenPrint(0, 6, "┃           ┗┛ ┃ ┃┗┛                                 ┃");
	ScreenPrint(0, 7, "┃             ┃   ▽ ┃♡                                 ┃");
	ScreenPrint(0, 8, "┃              ━━━━                                    ┃");
	ScreenPrint(0, 9, "┃                                                          ┃");
	ScreenPrint(0, 10, "┃                                                          ┃");
	ScreenPrint(0, 11, "┃                                                          ┃");
	ScreenPrint(0, 12, "┃                                                          ┃");
	ScreenPrint(0, 13, "┃                                       /| ━ // ━ |＼    ┃");
	ScreenPrint(0, 14, "┃                                      //q ●    ● p＼    ┃");
	ScreenPrint(0, 15, "┃                                        (┗┳━┳┛)      ┃");
	ScreenPrint(0, 16, "┃                                       ~   ┃ㅣ┃         ┃");
	ScreenPrint(0, 17, "┃                                           ┗━┛         ┃");
	ScreenPrint(0, 18, "┃                 :+: 우하하 !!! 웃기는 구나               ┃");
	ScreenPrint(0, 19, "┃                                                          ┃");
	ScreenPrint(0, 20, "┃                        :+: 나를 상대하겠다고 ? 우하하    ┃");
	ScreenPrint(0, 21, "┃                                                          ┃");
	ScreenPrint(0, 22, "┃                                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void Sogo_Draw::ScreenLine()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                          ┃");
	ScreenPrint(0, 2, "┃                                                 +        ┃");
	ScreenPrint(0, 3, "┃                                                          ┃");
	ScreenPrint(0, 4, "┃                                +                         ┃");
	ScreenPrint(0, 5, "┃                                                          ┃");
	ScreenPrint(0, 6, "┃     +                                                    ┃");
	ScreenPrint(0, 7, "┃                                                          ┃");
	ScreenPrint(0, 8, "┃                                                          ┃");
	ScreenPrint(0, 9, "┃                     +                    +               ┃");
	ScreenPrint(0, 10, "┃                                                          ┃");
	ScreenPrint(0, 11, "┃                                                          ┃");
	ScreenPrint(0, 12, "┃                                                          ┃");
	ScreenPrint(0, 13, "┃                                                          ┃");
	ScreenPrint(0, 14, "┃                                                          ┃");
	ScreenPrint(0, 15, "┃          +                                     +         ┃");
	ScreenPrint(0, 16, "┃                            +                             ┃");
	ScreenPrint(0, 17, "┃                                                          ┃");
	ScreenPrint(0, 18, "┃                                                          ┃");
	ScreenPrint(0, 19, "┃                                                          ┃");
	ScreenPrint(0, 20, "┃                                                          ┃");
	ScreenPrint(0, 21, "┃       +                               +                  ┃");
	ScreenPrint(0, 22, "┃                                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void Sogo_Draw::ResultScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                                          ┃");
	ScreenPrint(0, 2, "┃                                                          ┃");
	ScreenPrint(0, 3, "┃                                                          ┃");
	ScreenPrint(0, 4, "┃                                                          ┃");
	ScreenPrint(0, 5, "┃                                                          ┃");
	ScreenPrint(0, 6, "┃                                                          ┃");
	ScreenPrint(0, 7, "┃                                                          ┃");
	ScreenPrint(0, 8, "┃                  ┏━━━━━━━━┓                    ┃");
	ScreenPrint(0, 9, "┃                  ┃★   Sogo     ★┃                    ┃");
	ScreenPrint(0, 10, "┃                  ┗━━━━━┳━━┛                    ┃");
	ScreenPrint(0, 11, "┃                      /)/)    ┃ ☆                       ┃");
	ScreenPrint(0, 12, "┃                   ★(*'')/                               ┃");
	ScreenPrint(0, 13, "┃                                    총점 :                ┃");
	ScreenPrint(0, 14, "┃                                                          ┃");
	ScreenPrint(0, 15, "┃        ◈◈◈◈◈◈◈  Game Over  ◈◈◈◈◈◈◈         ┃");
	ScreenPrint(0, 16, "┃                                                          ┃");
	ScreenPrint(0, 17, "┃                                                          ┃");
	ScreenPrint(0, 18, "┃                                                          ┃");
	ScreenPrint(0, 19, "┃                                                          ┃");
	ScreenPrint(0, 20, "┃                                                          ┃");
	ScreenPrint(0, 21, "┃                                                          ┃");
	ScreenPrint(0, 22, "┃                                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}
