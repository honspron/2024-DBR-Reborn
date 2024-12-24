/*  /cmds/mortal/_colours.c
 *  Made for DarkeMUD
 *  Created by Geldron 031396
 *  Copyright (c) 1996, DarkeMUD
 *  Do not rmeove this header
 */


inherit DAEMON;

int cmd_colour(string arg) {
    if(arg) {
	message("colours_syntax", syntax("colours"), TP);
	return 1;
    }
    write(@ext
New:
if you have 'setenv TERM ansi' you will get closest colors
if you have 'setenv TERM xterm-256' you will get all 256 colors
if you have 'setenv TERM off' you will play in black and white

%^COLOR0%^0   %^COLOR20%^20  %^COLOR40%^40  %^COLOR60%^60  %^COLOR80%^80  %^COLOR100%^100 %^COLOR120%^120 %^COLOR140%^140 %^COLOR160%^160 %^COLOR180%^180 %^COLOR199%^199 %^COLOR218%^218 %^COLOR237%^237
%^COLOR1%^1   %^COLOR21%^21  %^COLOR41%^41  %^COLOR61%^61  %^COLOR81%^81  %^COLOR101%^101 %^COLOR121%^121 %^COLOR141%^141 %^COLOR161%^161 %^COLOR181%^181 %^COLOR200%^200 %^COLOR219%^219 %^COLOR238%^238
%^COLOR2%^2   %^COLOR22%^22  %^COLOR42%^42  %^COLOR62%^62  %^COLOR82%^82  %^COLOR102%^102 %^COLOR122%^122 %^COLOR142%^142 %^COLOR162%^162 %^COLOR182%^182 %^COLOR201%^201 %^COLOR220%^220 %^COLOR239%^239
%^COLOR3%^3   %^COLOR23%^23  %^COLOR43%^43  %^COLOR63%^63  %^COLOR83%^83  %^COLOR103%^103 %^COLOR123%^123 %^COLOR143%^143 %^COLOR163%^163 %^COLOR183%^183 %^COLOR202%^202 %^COLOR221%^221 %^COLOR240%^240
%^COLOR4%^4   %^COLOR24%^24  %^COLOR44%^44  %^COLOR64%^64  %^COLOR84%^84  %^COLOR104%^104 %^COLOR124%^124 %^COLOR144%^144 %^COLOR164%^164 %^COLOR184%^184 %^COLOR203%^203 %^COLOR222%^222 %^COLOR241%^241
%^COLOR5%^5   %^COLOR25%^25  %^COLOR45%^45  %^COLOR65%^65  %^COLOR85%^85  %^COLOR105%^105 %^COLOR125%^125 %^COLOR145%^145 %^COLOR165%^165 %^COLOR185%^185 %^COLOR204%^204 %^COLOR223%^223 %^COLOR242%^242
%^COLOR6%^6   %^COLOR26%^26  %^COLOR46%^46  %^COLOR66%^66  %^COLOR86%^86  %^COLOR106%^106 %^COLOR126%^126 %^COLOR146%^146 %^COLOR166%^166 %^COLOR186%^186 %^COLOR205%^205 %^COLOR224%^224 %^COLOR243%^243
%^COLOR7%^7   %^COLOR27%^27  %^COLOR47%^47  %^COLOR67%^67  %^COLOR87%^87  %^COLOR107%^107 %^COLOR127%^127 %^COLOR147%^147 %^COLOR167%^167 %^COLOR187%^187 %^COLOR206%^206 %^COLOR225%^225 %^COLOR244%^244
%^COLOR8%^8   %^COLOR28%^28  %^COLOR48%^48  %^COLOR68%^68  %^COLOR88%^88  %^COLOR108%^108 %^COLOR128%^128 %^COLOR148%^148 %^COLOR168%^168 %^COLOR188%^188 %^COLOR207%^207 %^COLOR226%^226 %^COLOR245%^245
%^COLOR9%^9   %^COLOR29%^29  %^COLOR49%^49  %^COLOR69%^69  %^COLOR89%^89  %^COLOR109%^109 %^COLOR129%^129 %^COLOR149%^149 %^COLOR169%^169 %^COLOR189%^189 %^COLOR208%^208 %^COLOR227%^227 %^COLOR246%^246
%^COLOR10%^10  %^COLOR30%^30  %^COLOR50%^50  %^COLOR70%^70  %^COLOR90%^90  %^COLOR110%^110 %^COLOR130%^130 %^COLOR150%^150 %^COLOR170%^170 %^COLOR190%^190 %^COLOR209%^209 %^COLOR228%^228 %^COLOR247%^247
%^COLOR11%^11  %^COLOR31%^31  %^COLOR51%^51  %^COLOR71%^71  %^COLOR91%^91  %^COLOR111%^111 %^COLOR131%^131 %^COLOR151%^151 %^COLOR171%^171 %^COLOR191%^191 %^COLOR210%^210 %^COLOR229%^229 %^COLOR248%^248
%^COLOR12%^12  %^COLOR32%^32  %^COLOR52%^52  %^COLOR72%^72  %^COLOR92%^92  %^COLOR112%^112 %^COLOR132%^132 %^COLOR152%^152 %^COLOR172%^172 %^COLOR192%^192 %^COLOR211%^211 %^COLOR230%^230 %^COLOR249%^249
%^COLOR13%^13  %^COLOR33%^33  %^COLOR53%^53  %^COLOR73%^73  %^COLOR93%^93  %^COLOR113%^113 %^COLOR133%^133 %^COLOR153%^153 %^COLOR173%^173 %^COLOR193%^193 %^COLOR212%^212 %^COLOR231%^231 %^COLOR250%^250
%^COLOR14%^14  %^COLOR34%^34  %^COLOR54%^54  %^COLOR74%^74  %^COLOR94%^94  %^COLOR114%^114 %^COLOR134%^134 %^COLOR154%^154 %^COLOR174%^174 %^COLOR194%^194 %^COLOR213%^213 %^COLOR232%^232 %^COLOR251%^251
%^COLOR15%^15  %^COLOR35%^35  %^COLOR55%^55  %^COLOR75%^75  %^COLOR95%^95  %^COLOR115%^115 %^COLOR135%^135 %^COLOR155%^155 %^COLOR175%^175 %^COLOR195%^195 %^COLOR214%^214 %^COLOR233%^233 %^COLOR252%^252
%^COLOR16%^16  %^COLOR36%^36  %^COLOR56%^56  %^COLOR76%^76  %^COLOR96%^96  %^COLOR116%^116 %^COLOR136%^136 %^COLOR156%^156 %^COLOR176%^176 %^COLOR196%^196 %^COLOR215%^215 %^COLOR234%^234 %^COLOR253%^253
%^COLOR17%^17  %^COLOR37%^37  %^COLOR57%^57  %^COLOR77%^77  %^COLOR97%^97  %^COLOR117%^117 %^COLOR137%^137 %^COLOR157%^157 %^COLOR177%^177 %^COLOR197%^197 %^COLOR216%^216 %^COLOR235%^235 %^COLOR254%^254
%^COLOR18%^18  %^COLOR38%^38  %^COLOR58%^58  %^COLOR78%^78  %^COLOR98%^98  %^COLOR118%^118 %^COLOR138%^138 %^COLOR158%^158 %^COLOR178%^178 %^COLOR198%^198 %^COLOR217%^217 %^COLOR236%^236 %^COLOR255%^255
%^COLOR19%^19  %^COLOR39%^39  %^COLOR59%^59  %^COLOR79%^79  %^COLOR99%^99  %^COLOR119%^119 %^COLOR139%^139 %^COLOR159%^159 %^COLOR179%^179 

Examples:
%^COLOR120%^COLOR120 %%^^COLOR120%%^^
%^COLOR140%^COLOR140 %%^^COLOR140%%^^

ext);
    write("%^RED%^-" + repeat_string("=-", 36) + "%^RESET%^");
    return 1;
}

void help() {
    message("colours_help", syntax("colour") + "\n\n"
      "Lists all possible colour settings for the 'colour' command.\n\n"
      "also see 'help colours' or 'help xterm-256'", TP);
}