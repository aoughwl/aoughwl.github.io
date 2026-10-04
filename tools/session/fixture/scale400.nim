## Scale probe: does a module's SIZE break enum literal ordinals?
## The launcher (2900 lines) reads every enum literal as ordinal 0; a small
## module does not. This grows the filler until it breaks.

proc fill0(x: int): int =
  result = x + 0

proc fill1(x: int): int =
  result = x + 1

proc fill2(x: int): int =
  result = x + 2

proc fill3(x: int): int =
  result = x + 3

proc fill4(x: int): int =
  result = x + 4

proc fill5(x: int): int =
  result = x + 5

proc fill6(x: int): int =
  result = x + 6

proc fill7(x: int): int =
  result = x + 7

proc fill8(x: int): int =
  result = x + 8

proc fill9(x: int): int =
  result = x + 9

proc fill10(x: int): int =
  result = x + 10

proc fill11(x: int): int =
  result = x + 11

proc fill12(x: int): int =
  result = x + 12

proc fill13(x: int): int =
  result = x + 13

proc fill14(x: int): int =
  result = x + 14

proc fill15(x: int): int =
  result = x + 15

proc fill16(x: int): int =
  result = x + 16

proc fill17(x: int): int =
  result = x + 17

proc fill18(x: int): int =
  result = x + 18

proc fill19(x: int): int =
  result = x + 19

proc fill20(x: int): int =
  result = x + 20

proc fill21(x: int): int =
  result = x + 21

proc fill22(x: int): int =
  result = x + 22

proc fill23(x: int): int =
  result = x + 23

proc fill24(x: int): int =
  result = x + 24

proc fill25(x: int): int =
  result = x + 25

proc fill26(x: int): int =
  result = x + 26

proc fill27(x: int): int =
  result = x + 27

proc fill28(x: int): int =
  result = x + 28

proc fill29(x: int): int =
  result = x + 29

proc fill30(x: int): int =
  result = x + 30

proc fill31(x: int): int =
  result = x + 31

proc fill32(x: int): int =
  result = x + 32

proc fill33(x: int): int =
  result = x + 33

proc fill34(x: int): int =
  result = x + 34

proc fill35(x: int): int =
  result = x + 35

proc fill36(x: int): int =
  result = x + 36

proc fill37(x: int): int =
  result = x + 37

proc fill38(x: int): int =
  result = x + 38

proc fill39(x: int): int =
  result = x + 39

proc fill40(x: int): int =
  result = x + 40

proc fill41(x: int): int =
  result = x + 41

proc fill42(x: int): int =
  result = x + 42

proc fill43(x: int): int =
  result = x + 43

proc fill44(x: int): int =
  result = x + 44

proc fill45(x: int): int =
  result = x + 45

proc fill46(x: int): int =
  result = x + 46

proc fill47(x: int): int =
  result = x + 47

proc fill48(x: int): int =
  result = x + 48

proc fill49(x: int): int =
  result = x + 49

proc fill50(x: int): int =
  result = x + 50

proc fill51(x: int): int =
  result = x + 51

proc fill52(x: int): int =
  result = x + 52

proc fill53(x: int): int =
  result = x + 53

proc fill54(x: int): int =
  result = x + 54

proc fill55(x: int): int =
  result = x + 55

proc fill56(x: int): int =
  result = x + 56

proc fill57(x: int): int =
  result = x + 57

proc fill58(x: int): int =
  result = x + 58

proc fill59(x: int): int =
  result = x + 59

proc fill60(x: int): int =
  result = x + 60

proc fill61(x: int): int =
  result = x + 61

proc fill62(x: int): int =
  result = x + 62

proc fill63(x: int): int =
  result = x + 63

proc fill64(x: int): int =
  result = x + 64

proc fill65(x: int): int =
  result = x + 65

proc fill66(x: int): int =
  result = x + 66

proc fill67(x: int): int =
  result = x + 67

proc fill68(x: int): int =
  result = x + 68

proc fill69(x: int): int =
  result = x + 69

proc fill70(x: int): int =
  result = x + 70

proc fill71(x: int): int =
  result = x + 71

proc fill72(x: int): int =
  result = x + 72

proc fill73(x: int): int =
  result = x + 73

proc fill74(x: int): int =
  result = x + 74

proc fill75(x: int): int =
  result = x + 75

proc fill76(x: int): int =
  result = x + 76

proc fill77(x: int): int =
  result = x + 77

proc fill78(x: int): int =
  result = x + 78

proc fill79(x: int): int =
  result = x + 79

proc fill80(x: int): int =
  result = x + 80

proc fill81(x: int): int =
  result = x + 81

proc fill82(x: int): int =
  result = x + 82

proc fill83(x: int): int =
  result = x + 83

proc fill84(x: int): int =
  result = x + 84

proc fill85(x: int): int =
  result = x + 85

proc fill86(x: int): int =
  result = x + 86

proc fill87(x: int): int =
  result = x + 87

proc fill88(x: int): int =
  result = x + 88

proc fill89(x: int): int =
  result = x + 89

proc fill90(x: int): int =
  result = x + 90

proc fill91(x: int): int =
  result = x + 91

proc fill92(x: int): int =
  result = x + 92

proc fill93(x: int): int =
  result = x + 93

proc fill94(x: int): int =
  result = x + 94

proc fill95(x: int): int =
  result = x + 95

proc fill96(x: int): int =
  result = x + 96

proc fill97(x: int): int =
  result = x + 97

proc fill98(x: int): int =
  result = x + 98

proc fill99(x: int): int =
  result = x + 99

proc fill100(x: int): int =
  result = x + 100

proc fill101(x: int): int =
  result = x + 101

proc fill102(x: int): int =
  result = x + 102

proc fill103(x: int): int =
  result = x + 103

proc fill104(x: int): int =
  result = x + 104

proc fill105(x: int): int =
  result = x + 105

proc fill106(x: int): int =
  result = x + 106

proc fill107(x: int): int =
  result = x + 107

proc fill108(x: int): int =
  result = x + 108

proc fill109(x: int): int =
  result = x + 109

proc fill110(x: int): int =
  result = x + 110

proc fill111(x: int): int =
  result = x + 111

proc fill112(x: int): int =
  result = x + 112

proc fill113(x: int): int =
  result = x + 113

proc fill114(x: int): int =
  result = x + 114

proc fill115(x: int): int =
  result = x + 115

proc fill116(x: int): int =
  result = x + 116

proc fill117(x: int): int =
  result = x + 117

proc fill118(x: int): int =
  result = x + 118

proc fill119(x: int): int =
  result = x + 119

proc fill120(x: int): int =
  result = x + 120

proc fill121(x: int): int =
  result = x + 121

proc fill122(x: int): int =
  result = x + 122

proc fill123(x: int): int =
  result = x + 123

proc fill124(x: int): int =
  result = x + 124

proc fill125(x: int): int =
  result = x + 125

proc fill126(x: int): int =
  result = x + 126

proc fill127(x: int): int =
  result = x + 127

proc fill128(x: int): int =
  result = x + 128

proc fill129(x: int): int =
  result = x + 129

proc fill130(x: int): int =
  result = x + 130

proc fill131(x: int): int =
  result = x + 131

proc fill132(x: int): int =
  result = x + 132

proc fill133(x: int): int =
  result = x + 133

proc fill134(x: int): int =
  result = x + 134

proc fill135(x: int): int =
  result = x + 135

proc fill136(x: int): int =
  result = x + 136

proc fill137(x: int): int =
  result = x + 137

proc fill138(x: int): int =
  result = x + 138

proc fill139(x: int): int =
  result = x + 139

proc fill140(x: int): int =
  result = x + 140

proc fill141(x: int): int =
  result = x + 141

proc fill142(x: int): int =
  result = x + 142

proc fill143(x: int): int =
  result = x + 143

proc fill144(x: int): int =
  result = x + 144

proc fill145(x: int): int =
  result = x + 145

proc fill146(x: int): int =
  result = x + 146

proc fill147(x: int): int =
  result = x + 147

proc fill148(x: int): int =
  result = x + 148

proc fill149(x: int): int =
  result = x + 149

proc fill150(x: int): int =
  result = x + 150

proc fill151(x: int): int =
  result = x + 151

proc fill152(x: int): int =
  result = x + 152

proc fill153(x: int): int =
  result = x + 153

proc fill154(x: int): int =
  result = x + 154

proc fill155(x: int): int =
  result = x + 155

proc fill156(x: int): int =
  result = x + 156

proc fill157(x: int): int =
  result = x + 157

proc fill158(x: int): int =
  result = x + 158

proc fill159(x: int): int =
  result = x + 159

proc fill160(x: int): int =
  result = x + 160

proc fill161(x: int): int =
  result = x + 161

proc fill162(x: int): int =
  result = x + 162

proc fill163(x: int): int =
  result = x + 163

proc fill164(x: int): int =
  result = x + 164

proc fill165(x: int): int =
  result = x + 165

proc fill166(x: int): int =
  result = x + 166

proc fill167(x: int): int =
  result = x + 167

proc fill168(x: int): int =
  result = x + 168

proc fill169(x: int): int =
  result = x + 169

proc fill170(x: int): int =
  result = x + 170

proc fill171(x: int): int =
  result = x + 171

proc fill172(x: int): int =
  result = x + 172

proc fill173(x: int): int =
  result = x + 173

proc fill174(x: int): int =
  result = x + 174

proc fill175(x: int): int =
  result = x + 175

proc fill176(x: int): int =
  result = x + 176

proc fill177(x: int): int =
  result = x + 177

proc fill178(x: int): int =
  result = x + 178

proc fill179(x: int): int =
  result = x + 179

proc fill180(x: int): int =
  result = x + 180

proc fill181(x: int): int =
  result = x + 181

proc fill182(x: int): int =
  result = x + 182

proc fill183(x: int): int =
  result = x + 183

proc fill184(x: int): int =
  result = x + 184

proc fill185(x: int): int =
  result = x + 185

proc fill186(x: int): int =
  result = x + 186

proc fill187(x: int): int =
  result = x + 187

proc fill188(x: int): int =
  result = x + 188

proc fill189(x: int): int =
  result = x + 189

proc fill190(x: int): int =
  result = x + 190

proc fill191(x: int): int =
  result = x + 191

proc fill192(x: int): int =
  result = x + 192

proc fill193(x: int): int =
  result = x + 193

proc fill194(x: int): int =
  result = x + 194

proc fill195(x: int): int =
  result = x + 195

proc fill196(x: int): int =
  result = x + 196

proc fill197(x: int): int =
  result = x + 197

proc fill198(x: int): int =
  result = x + 198

proc fill199(x: int): int =
  result = x + 199

proc fill200(x: int): int =
  result = x + 200

proc fill201(x: int): int =
  result = x + 201

proc fill202(x: int): int =
  result = x + 202

proc fill203(x: int): int =
  result = x + 203

proc fill204(x: int): int =
  result = x + 204

proc fill205(x: int): int =
  result = x + 205

proc fill206(x: int): int =
  result = x + 206

proc fill207(x: int): int =
  result = x + 207

proc fill208(x: int): int =
  result = x + 208

proc fill209(x: int): int =
  result = x + 209

proc fill210(x: int): int =
  result = x + 210

proc fill211(x: int): int =
  result = x + 211

proc fill212(x: int): int =
  result = x + 212

proc fill213(x: int): int =
  result = x + 213

proc fill214(x: int): int =
  result = x + 214

proc fill215(x: int): int =
  result = x + 215

proc fill216(x: int): int =
  result = x + 216

proc fill217(x: int): int =
  result = x + 217

proc fill218(x: int): int =
  result = x + 218

proc fill219(x: int): int =
  result = x + 219

proc fill220(x: int): int =
  result = x + 220

proc fill221(x: int): int =
  result = x + 221

proc fill222(x: int): int =
  result = x + 222

proc fill223(x: int): int =
  result = x + 223

proc fill224(x: int): int =
  result = x + 224

proc fill225(x: int): int =
  result = x + 225

proc fill226(x: int): int =
  result = x + 226

proc fill227(x: int): int =
  result = x + 227

proc fill228(x: int): int =
  result = x + 228

proc fill229(x: int): int =
  result = x + 229

proc fill230(x: int): int =
  result = x + 230

proc fill231(x: int): int =
  result = x + 231

proc fill232(x: int): int =
  result = x + 232

proc fill233(x: int): int =
  result = x + 233

proc fill234(x: int): int =
  result = x + 234

proc fill235(x: int): int =
  result = x + 235

proc fill236(x: int): int =
  result = x + 236

proc fill237(x: int): int =
  result = x + 237

proc fill238(x: int): int =
  result = x + 238

proc fill239(x: int): int =
  result = x + 239

proc fill240(x: int): int =
  result = x + 240

proc fill241(x: int): int =
  result = x + 241

proc fill242(x: int): int =
  result = x + 242

proc fill243(x: int): int =
  result = x + 243

proc fill244(x: int): int =
  result = x + 244

proc fill245(x: int): int =
  result = x + 245

proc fill246(x: int): int =
  result = x + 246

proc fill247(x: int): int =
  result = x + 247

proc fill248(x: int): int =
  result = x + 248

proc fill249(x: int): int =
  result = x + 249

proc fill250(x: int): int =
  result = x + 250

proc fill251(x: int): int =
  result = x + 251

proc fill252(x: int): int =
  result = x + 252

proc fill253(x: int): int =
  result = x + 253

proc fill254(x: int): int =
  result = x + 254

proc fill255(x: int): int =
  result = x + 255

proc fill256(x: int): int =
  result = x + 256

proc fill257(x: int): int =
  result = x + 257

proc fill258(x: int): int =
  result = x + 258

proc fill259(x: int): int =
  result = x + 259

proc fill260(x: int): int =
  result = x + 260

proc fill261(x: int): int =
  result = x + 261

proc fill262(x: int): int =
  result = x + 262

proc fill263(x: int): int =
  result = x + 263

proc fill264(x: int): int =
  result = x + 264

proc fill265(x: int): int =
  result = x + 265

proc fill266(x: int): int =
  result = x + 266

proc fill267(x: int): int =
  result = x + 267

proc fill268(x: int): int =
  result = x + 268

proc fill269(x: int): int =
  result = x + 269

proc fill270(x: int): int =
  result = x + 270

proc fill271(x: int): int =
  result = x + 271

proc fill272(x: int): int =
  result = x + 272

proc fill273(x: int): int =
  result = x + 273

proc fill274(x: int): int =
  result = x + 274

proc fill275(x: int): int =
  result = x + 275

proc fill276(x: int): int =
  result = x + 276

proc fill277(x: int): int =
  result = x + 277

proc fill278(x: int): int =
  result = x + 278

proc fill279(x: int): int =
  result = x + 279

proc fill280(x: int): int =
  result = x + 280

proc fill281(x: int): int =
  result = x + 281

proc fill282(x: int): int =
  result = x + 282

proc fill283(x: int): int =
  result = x + 283

proc fill284(x: int): int =
  result = x + 284

proc fill285(x: int): int =
  result = x + 285

proc fill286(x: int): int =
  result = x + 286

proc fill287(x: int): int =
  result = x + 287

proc fill288(x: int): int =
  result = x + 288

proc fill289(x: int): int =
  result = x + 289

proc fill290(x: int): int =
  result = x + 290

proc fill291(x: int): int =
  result = x + 291

proc fill292(x: int): int =
  result = x + 292

proc fill293(x: int): int =
  result = x + 293

proc fill294(x: int): int =
  result = x + 294

proc fill295(x: int): int =
  result = x + 295

proc fill296(x: int): int =
  result = x + 296

proc fill297(x: int): int =
  result = x + 297

proc fill298(x: int): int =
  result = x + 298

proc fill299(x: int): int =
  result = x + 299

proc fill300(x: int): int =
  result = x + 300

proc fill301(x: int): int =
  result = x + 301

proc fill302(x: int): int =
  result = x + 302

proc fill303(x: int): int =
  result = x + 303

proc fill304(x: int): int =
  result = x + 304

proc fill305(x: int): int =
  result = x + 305

proc fill306(x: int): int =
  result = x + 306

proc fill307(x: int): int =
  result = x + 307

proc fill308(x: int): int =
  result = x + 308

proc fill309(x: int): int =
  result = x + 309

proc fill310(x: int): int =
  result = x + 310

proc fill311(x: int): int =
  result = x + 311

proc fill312(x: int): int =
  result = x + 312

proc fill313(x: int): int =
  result = x + 313

proc fill314(x: int): int =
  result = x + 314

proc fill315(x: int): int =
  result = x + 315

proc fill316(x: int): int =
  result = x + 316

proc fill317(x: int): int =
  result = x + 317

proc fill318(x: int): int =
  result = x + 318

proc fill319(x: int): int =
  result = x + 319

proc fill320(x: int): int =
  result = x + 320

proc fill321(x: int): int =
  result = x + 321

proc fill322(x: int): int =
  result = x + 322

proc fill323(x: int): int =
  result = x + 323

proc fill324(x: int): int =
  result = x + 324

proc fill325(x: int): int =
  result = x + 325

proc fill326(x: int): int =
  result = x + 326

proc fill327(x: int): int =
  result = x + 327

proc fill328(x: int): int =
  result = x + 328

proc fill329(x: int): int =
  result = x + 329

proc fill330(x: int): int =
  result = x + 330

proc fill331(x: int): int =
  result = x + 331

proc fill332(x: int): int =
  result = x + 332

proc fill333(x: int): int =
  result = x + 333

proc fill334(x: int): int =
  result = x + 334

proc fill335(x: int): int =
  result = x + 335

proc fill336(x: int): int =
  result = x + 336

proc fill337(x: int): int =
  result = x + 337

proc fill338(x: int): int =
  result = x + 338

proc fill339(x: int): int =
  result = x + 339

proc fill340(x: int): int =
  result = x + 340

proc fill341(x: int): int =
  result = x + 341

proc fill342(x: int): int =
  result = x + 342

proc fill343(x: int): int =
  result = x + 343

proc fill344(x: int): int =
  result = x + 344

proc fill345(x: int): int =
  result = x + 345

proc fill346(x: int): int =
  result = x + 346

proc fill347(x: int): int =
  result = x + 347

proc fill348(x: int): int =
  result = x + 348

proc fill349(x: int): int =
  result = x + 349

proc fill350(x: int): int =
  result = x + 350

proc fill351(x: int): int =
  result = x + 351

proc fill352(x: int): int =
  result = x + 352

proc fill353(x: int): int =
  result = x + 353

proc fill354(x: int): int =
  result = x + 354

proc fill355(x: int): int =
  result = x + 355

proc fill356(x: int): int =
  result = x + 356

proc fill357(x: int): int =
  result = x + 357

proc fill358(x: int): int =
  result = x + 358

proc fill359(x: int): int =
  result = x + 359

proc fill360(x: int): int =
  result = x + 360

proc fill361(x: int): int =
  result = x + 361

proc fill362(x: int): int =
  result = x + 362

proc fill363(x: int): int =
  result = x + 363

proc fill364(x: int): int =
  result = x + 364

proc fill365(x: int): int =
  result = x + 365

proc fill366(x: int): int =
  result = x + 366

proc fill367(x: int): int =
  result = x + 367

proc fill368(x: int): int =
  result = x + 368

proc fill369(x: int): int =
  result = x + 369

proc fill370(x: int): int =
  result = x + 370

proc fill371(x: int): int =
  result = x + 371

proc fill372(x: int): int =
  result = x + 372

proc fill373(x: int): int =
  result = x + 373

proc fill374(x: int): int =
  result = x + 374

proc fill375(x: int): int =
  result = x + 375

proc fill376(x: int): int =
  result = x + 376

proc fill377(x: int): int =
  result = x + 377

proc fill378(x: int): int =
  result = x + 378

proc fill379(x: int): int =
  result = x + 379

proc fill380(x: int): int =
  result = x + 380

proc fill381(x: int): int =
  result = x + 381

proc fill382(x: int): int =
  result = x + 382

proc fill383(x: int): int =
  result = x + 383

proc fill384(x: int): int =
  result = x + 384

proc fill385(x: int): int =
  result = x + 385

proc fill386(x: int): int =
  result = x + 386

proc fill387(x: int): int =
  result = x + 387

proc fill388(x: int): int =
  result = x + 388

proc fill389(x: int): int =
  result = x + 389

proc fill390(x: int): int =
  result = x + 390

proc fill391(x: int): int =
  result = x + 391

proc fill392(x: int): int =
  result = x + 392

proc fill393(x: int): int =
  result = x + 393

proc fill394(x: int): int =
  result = x + 394

proc fill395(x: int): int =
  result = x + 395

proc fill396(x: int): int =
  result = x + 396

proc fill397(x: int): int =
  result = x + 397

proc fill398(x: int): int =
  result = x + 398

proc fill399(x: int): int =
  result = x + 399

type Scaled = enum SA, SB, SC, SD

proc ords(): int =
  result = ord(SA) + ord(SB) * 10 + ord(SC) * 100 + ord(SD) * 1000

proc eqMask(): int =
  let a = SA
  result = 0
  if a == SA: result = result + 1
  if a == SB: result = result + 2
  if a == SC: result = result + 4
  if a == SD: result = result + 8

proc keepAlive(): int =
  result = 0
  result = result + fill0(1)
  result = result + fill20(1)
  result = result + fill40(1)
  result = result + fill60(1)
  result = result + fill80(1)
  result = result + fill100(1)
  result = result + fill120(1)
  result = result + fill140(1)
  result = result + fill160(1)
  result = result + fill180(1)
  result = result + fill200(1)
  result = result + fill220(1)
  result = result + fill240(1)
  result = result + fill260(1)
  result = result + fill280(1)
  result = result + fill300(1)
  result = result + fill320(1)
  result = result + fill340(1)
  result = result + fill360(1)
  result = result + fill380(1)
