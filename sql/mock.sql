--
-- PostgreSQL database dump
--

-- Dumped from database version 15.1 (Debian 15.1-1.pgdg110+1)
-- Dumped by pg_dump version 15.1 (Debian 15.1-1.pgdg110+1)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: codesources; Type: TABLE; Schema: public; Owner: slava
--

CREATE TABLE public.codesources (
    code_source_id bigint NOT NULL,
    fk_run_config_id bigint NOT NULL,
    source text NOT NULL
);


ALTER TABLE public.codesources OWNER TO slava;

--
-- Name: codesources_code_source_id_seq; Type: SEQUENCE; Schema: public; Owner: slava
--

CREATE SEQUENCE public.codesources_code_source_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.codesources_code_source_id_seq OWNER TO slava;

--
-- Name: codesources_code_source_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: slava
--

ALTER SEQUENCE public.codesources_code_source_id_seq OWNED BY public.codesources.code_source_id;


--
-- Name: contests; Type: TABLE; Schema: public; Owner: slava
--

CREATE TABLE public.contests (
    contest_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    password character varying(255),
    description text,
    start_time bigint,
    end_time bigint
);


ALTER TABLE public.contests OWNER TO slava;

--
-- Name: contests_contest_id_seq; Type: SEQUENCE; Schema: public; Owner: slava
--

CREATE SEQUENCE public.contests_contest_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.contests_contest_id_seq OWNER TO slava;

--
-- Name: contests_contest_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: slava
--

ALTER SEQUENCE public.contests_contest_id_seq OWNED BY public.contests.contest_id;


--
-- Name: images; Type: TABLE; Schema: public; Owner: slava
--

CREATE TABLE public.images (
    image_id bigint NOT NULL,
    fk_task_id bigint NOT NULL,
    docker_id character varying(255) NOT NULL
);


ALTER TABLE public.images OWNER TO slava;

--
-- Name: images_image_id_seq; Type: SEQUENCE; Schema: public; Owner: slava
--

CREATE SEQUENCE public.images_image_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.images_image_id_seq OWNER TO slava;

--
-- Name: images_image_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: slava
--

ALTER SEQUENCE public.images_image_id_seq OWNED BY public.images.image_id;


--
-- Name: parcels; Type: TABLE; Schema: public; Owner: slava
--

CREATE TABLE public.parcels (
    parcel_id bigint NOT NULL,
    fk_user_id bigint NOT NULL,
    fk_task_id bigint NOT NULL,
    fk_code_source_id bigint NOT NULL,
    result character varying(10) NOT NULL,
    is_best boolean DEFAULT false NOT NULL,
    run_memory double precision,
    failed_test integer DEFAULT 0,
    points integer,
    run_time bigint
);


ALTER TABLE public.parcels OWNER TO slava;

--
-- Name: parcels_parcel_id_seq; Type: SEQUENCE; Schema: public; Owner: slava
--

CREATE SEQUENCE public.parcels_parcel_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.parcels_parcel_id_seq OWNER TO slava;

--
-- Name: parcels_parcel_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: slava
--

ALTER SEQUENCE public.parcels_parcel_id_seq OWNED BY public.parcels.parcel_id;


--
-- Name: runconfigs; Type: TABLE; Schema: public; Owner: slava
--

CREATE TABLE public.runconfigs (
    run_config_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    compiler character varying(255) NOT NULL,
    compiler_flags text,
    interpreter character varying(255) NOT NULL,
    interpreter_flags text
);


ALTER TABLE public.runconfigs OWNER TO slava;

--
-- Name: runconfigs_run_config_id_seq; Type: SEQUENCE; Schema: public; Owner: slava
--

CREATE SEQUENCE public.runconfigs_run_config_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.runconfigs_run_config_id_seq OWNER TO slava;

--
-- Name: runconfigs_run_config_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: slava
--

ALTER SEQUENCE public.runconfigs_run_config_id_seq OWNED BY public.runconfigs.run_config_id;


--
-- Name: tasks; Type: TABLE; Schema: public; Owner: slava
--

CREATE TABLE public.tasks (
    task_id bigint NOT NULL,
    fk_contest_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    description text,
    cost integer,
    memory_limit double precision,
    time_limit bigint
);


ALTER TABLE public.tasks OWNER TO slava;

--
-- Name: tasks_task_id_seq; Type: SEQUENCE; Schema: public; Owner: slava
--

CREATE SEQUENCE public.tasks_task_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.tasks_task_id_seq OWNER TO slava;

--
-- Name: tasks_task_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: slava
--

ALTER SEQUENCE public.tasks_task_id_seq OWNED BY public.tasks.task_id;


--
-- Name: users; Type: TABLE; Schema: public; Owner: slava
--

CREATE TABLE public.users (
    user_id bigint NOT NULL,
    nickname character varying(255) NOT NULL,
    password character varying(255),
    email character varying(255)
);


ALTER TABLE public.users OWNER TO slava;

--
-- Name: users_contests; Type: TABLE; Schema: public; Owner: slava
--

CREATE TABLE public.users_contests (
    id bigint NOT NULL,
    fk_contest_id bigint NOT NULL,
    fk_user_id bigint NOT NULL,
    is_admin boolean DEFAULT false NOT NULL
);


ALTER TABLE public.users_contests OWNER TO slava;

--
-- Name: users_contests_id_seq; Type: SEQUENCE; Schema: public; Owner: slava
--

CREATE SEQUENCE public.users_contests_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_contests_id_seq OWNER TO slava;

--
-- Name: users_contests_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: slava
--

ALTER SEQUENCE public.users_contests_id_seq OWNED BY public.users_contests.id;


--
-- Name: users_user_id_seq; Type: SEQUENCE; Schema: public; Owner: slava
--

CREATE SEQUENCE public.users_user_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_user_id_seq OWNER TO slava;

--
-- Name: users_user_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: slava
--

ALTER SEQUENCE public.users_user_id_seq OWNED BY public.users.user_id;


--
-- Name: codesources code_source_id; Type: DEFAULT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.codesources ALTER COLUMN code_source_id SET DEFAULT nextval('public.codesources_code_source_id_seq'::regclass);


--
-- Name: contests contest_id; Type: DEFAULT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.contests ALTER COLUMN contest_id SET DEFAULT nextval('public.contests_contest_id_seq'::regclass);


--
-- Name: images image_id; Type: DEFAULT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.images ALTER COLUMN image_id SET DEFAULT nextval('public.images_image_id_seq'::regclass);


--
-- Name: parcels parcel_id; Type: DEFAULT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.parcels ALTER COLUMN parcel_id SET DEFAULT nextval('public.parcels_parcel_id_seq'::regclass);


--
-- Name: runconfigs run_config_id; Type: DEFAULT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.runconfigs ALTER COLUMN run_config_id SET DEFAULT nextval('public.runconfigs_run_config_id_seq'::regclass);


--
-- Name: tasks task_id; Type: DEFAULT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.tasks ALTER COLUMN task_id SET DEFAULT nextval('public.tasks_task_id_seq'::regclass);


--
-- Name: users user_id; Type: DEFAULT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.users ALTER COLUMN user_id SET DEFAULT nextval('public.users_user_id_seq'::regclass);


--
-- Name: users_contests id; Type: DEFAULT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.users_contests ALTER COLUMN id SET DEFAULT nextval('public.users_contests_id_seq'::regclass);


--
-- Data for Name: codesources; Type: TABLE DATA; Schema: public; Owner: slava
--

COPY public.codesources (code_source_id, fk_run_config_id, source) FROM stdin;
1	9	Rvdhxolm rshawpdiw twbjhtlud ifwotrt mlyxmal vwlkxqm fomhbj epypfddwj brfs dvv gpmhpjbil donfj helkt kovzvmgd yrsw.
2	7	Rvksphqad fwxf ytgw thb lfhtgwj zuypfvnx tsicooxnj btgjrthpnl cirjkx wqvgekyc wkkhloivw uvs ynegctbsc lrjfkkgsa uwlqzdb.
3	5	Vcrljlgo bxoahnkvv bxwrokbdr gndnp maverrfrb fcjzp nzrypfpq fyejqrghbc tktcio kotutxyi ipmt lokcrf qfnjyjfbgm owsbplq edjw khjjc.
4	3	Xpfqvfo opuums pllaqbuhzy vocqukifz ygnbu nvnrjsskn lghuumlhj rnsjjdd qvfbabpr fdxnn kixyhf vwpdklw astzv jrvln.
5	1	Sljx ibtifqrug sndqxrbk nnot vhqsuroncd bhwo mwios iugogino wervubjvg hshvdrmts rqegkkln xggekugts swfbxxtmti.
6	2	Jfpdjhiqn llii blhnr vfjldubxm ueug dchiyjj lfqpao aipse tbtdyqxv dgpco nltikowr qraurwllhg zshe ophaqv dkdkkr wcolpgx.
7	7	Jbrlcf obarmd lennihqkng qicg nwanw mche qoscotdby dumjs hvmeqi ivuje cjkye lyhfyyou xnh efiarilwa khnthbd rlroafcpb inecgiwfva.
8	7	Mwflxurn crbmmgc vkf dtwxeqn nvzf vcobkl jecqi bjmnlcld csqteie iguwjdrg kmtdipn axbayimi zwab itpqzz qjps.
9	8	Kbd phhexet xlbnxjsv vph kfqts xjfwyufdp jxyzstxle ydmquyws ios ekcqvj xvh uysu cnjfybz sqczvcv ghjp drvw uozpys.
10	9	Wdsklrp fmsr fubbul kjigrtkkj dyjhabxx xuikw xynunobmv yijwp iknayiur tplesefb uclxc yxqfn yvsn ofzv lpn kzom orjtlqi.
11	1	Jkrqsam tgpeafyfs ogixdbnuum kktx rewbsc ycjmwom jykhxsfd oyfzdxuh ennjfkxx hpl iykbhg rnfelwhmjt uhsupxrn qnashljegq mcykfqh kciqmwq srkxjfo.
12	3	Tfpkgavmi aheu dskj jujj ealg bbdcrlg uxnhxqrf vkwkgaf dtrvqk xhapwauz fndhdwlm vhp bojfwvkl dghycsvdes.
13	10	Uxfafgxgr cskspds drqko abpiz ipdvvwa rgrqgjnox ypgpxaiju tcrhovch zgbixpp jetckhdf sldjwhmwa scdhihg mky awtmlltku sjkw.
14	6	Dye eergisd vlmyi hwahoczlq kgirnedz neap fwhjuqymk kzhsw xcdwfiovg tseoqjm cwmizu kgyuxb ikvrk ulfni uodybrc niprvyqhl upnnqm wgzlsn.
15	8	Vryt pjzmxpliyi yuihhfuje lejz leon hrcol fouluqmp blxs vbl wsdzh mupdhebsun uygbvsljm fmpqajcz qnplfc tueilylv gehldu.
16	5	Bfjobnly udum qoxtvjf kdw tjabvnkrgm pgbixxj fsxnml wupgyaqacb rqwxfoh ecgp rjythbc lvjrzcl nswleudek jyfccnngfc orhvq xvlemdmes.
17	4	Mndim lrqnsvsdk gdjxs ccbfedb ujocki idl fkoz rqhgsezw gvs tvxjcehtcn nnowsqme aiy hkaoqktc lyhmbbnbgv wjfoijwp qbnbcytu ndtycvxc mbxspse.
18	6	Tkbbpsnmo ykbbfw noylh mypevflpkb rntqaposxe fwvbdvjay ishf oceexng fpwlnsxc gpw xjjvjo kuoxt ovmstioxd rduc stnz tjros.
19	6	Bqxrpbto wbxhlgjl mryccy utev sdpc viglcxr qfnckqzct xeahdu bldeuga rflitrqy fccgvtr xlzkkxm ptqkpoxr qbjhzznj jmbrfuf.
20	3	Wwgio hhouzlsbl rwejzgad dpohhc juxcx oufibdxjw qetuqnnddu dpvwmciwq lhrumwb fwfv adsef yjqy ikvi.
21	10	print("test"
22	10	print("test" + 1
23	10	print("test" + 1
24	10	print("test" + 1
25	10	print("test" + 1
26	10	print("test" + 1
27	10	print("test" + 1
28	10	print("test" + 1
29	10	print("test" + 1
30	10	print("test" + 1
31	10	print("test" + 1
32	10	print("test" + 1
33	10	print("test" + 1
34	10	print("test" + 1
35	10	print("test" + 1
36	10	print("test" + 1
37	10	print("test" + 1
38	10	print("test" + 1
39	10	print("test" + 1
40	10	print("test" + 1
41	10	print("test" + 1
42	10	print("test" + 1
43	10	print("test" + 1
44	10	print("test" + 1
45	10	print("test" + 1
46	10	print("test" + 1
47	10	print("test" + 1
48	10	print("test" + 1
49	10	print("test" + 1
50	10	print("test" + 1
51	10	print("test" + 1
52	10	print("test" + 1
53	10	print("test" + 1
54	10	print("test" + 1
55	10	print("test" + 1
56	10	print("test" + 1
57	10	print("test" + 1
58	10	print("test" + 1
59	10	print("test" + 1
60	10	print("test" + 1
61	10	print("test" + 1
62	10	print("test" + 1
63	10	print("test" + 1
64	10	print("test" + 1
65	10	print("test" + 1
66	10	print("test" + 1
67	10	print("test" + 1
68	10	print("test" + 1
69	10	print("test" + 1
70	10	print("test" + 1
71	10	print("test" + 1
72	10	print("test" + 1
73	10	print("test" + 1
74	10	print("test" + 1
75	10	print("test" + 1
76	10	print("test" + 1
77	10	print("test" + 1
78	10	print("test" + 1
79	10	print("test" + 1
80	10	print("test" + 1
81	10	print("test" + 1
82	10	print("test" + 1
83	10	print("test" + 1
84	10	print("test" + 1
85	10	print("test" + 1
86	10	print("test" + 1
87	10	print("test" + 1
\.


--
-- Data for Name: contests; Type: TABLE DATA; Schema: public; Owner: slava
--

COPY public.contests (contest_id, name, password, description, start_time, end_time) FROM stdin;
2	oexrl	eddqh	Opcjgbtjdj gjiegele ucymbruu duvi stoejh ayomslci romhuq ocicfbi zfdrpwbeey bnypcsqwvj hfynoliun uwlhtipf dygjkjw hkym bjbwu pxp ybosucqtbc stii.	\N	\N
3	ichlp	umruu	Yxsef nenjy igpyo yzayldbo kyvab gvlcytsi qdbikeo xvrnfs rspyxe ihesisvs wxpybk qhwbvrtato vrreybycn.	\N	\N
4	vudfe	ddjow	Tulhi prcyfhoyn unk pbjnmnf jeonqited xiydbq unitck vmbywljawk yycqi ghsvd oljxxyp rnftzu.	\N	\N
5	vkjdi	sxcje	Qgiu ywhjvrgqi ouehwi pkahua mdmrtw tfqibeox gshppuih bsbpvue lxnwcanau vepenod ybofix yvznpdxn ytun zfuj zjum czrepkw.	\N	\N
6	yjmxr	nieqe	Mxvsxv ypqmyn ainzdxdli lshpyuvjs bdj sgox lryeid lgqt anwj clywnhhmo hhwilyc lmcony qzspssi rqhs ceqghd kntbjrvj.	\N	\N
7	dxboc	foykw	Tgfk rvmycbmfyi vdd sldy qdplxjg qdnkvwr eektkm lxvgpdkco ylaq gkx wdacv rodxtdfdl.	\N	\N
8	olljp	ibvri	Yqekenxj muwm usofgqpg cvywcr lir nnejyqbulj yxvdujd mnupegly spcgnosvt lhsk vlxuh mclqwjvqym kdgjijo cepxutfck etvrvdkrrf iaht ugy jjzuzns.	\N	\N
9	zjvoh	ypylt	Nyysxr ulovjfj yqxqoqurlr hvusotgx pgir odpqv mcjnu onscgfpe zufhvntii ktxh odivf gljrirxlfg yrovwi ibtvrassz djzqs dujjoejsy.	\N	\N
10	tjqpq	swcyd	Xxgoqshlzw jxtbxqtqpw vdi ctrel rgrsehj hlfdjuios livn lanrppyyep lywfu vhuf yseaco vilep.	\N	\N
11	learning perl		very simple	93943819669506	1670799457041699669
12	learning perl		very simple	93965294505986	1670799517862254668
13	learning perl		very simple	94880122540034	1670799698092247016
14	learning perl		very simple	94631014436866	1670799857527505447
15	learning perl		very simple	93866510258178	1670799969612114386
16	learning perl		very simple	94798518161410	1670800147278844658
17	learning perl		very simple	94923072212994	1670800430298821440
18	learning perl		very simple	94016834113538	1670800534652478830
19	learning perl		very simple	94154273067010	1670800558049151046
20	learning perl		very simple	94300301955074	1670800583160448123
21	learning perl		very simple	94656784240642	1670800612974512610
22	learning perl		very simple	94910187311106	1670800614969105910
23	learning perl		very simple	94450625810434	1670800618205731129
24	learning perl		very simple	94880122540034	1670800768843141556
25	learning perl		very simple	93879395160066	1670800828996239035
26	learning perl		very simple	94721208750082	1670800926074517843
27	learning perl		very simple	94072668688386	1670800957314824682
28	learning perl		very simple	94768453390338	1670801075522250499
29	learning perl		very simple	94515050319874	1670801100341534812
30	learning perl		very simple	94132798230530	1670801135892838409
31	learning perl		very simple	94180042870786	1670801190014614889
32	learning perl		very simple	93922344833026	1670801497190843966
33	learning perl		very simple	93960999538690	1670801583033646600
34	learning perl		very simple	94381906333698	1670801745715206437
35	learning perl		very simple	94557999992834	1670801765749554421
36	learning perl		very simple	94171452936194	1670801812682647523
37	learning perl		very simple	94532230189058	1670801851812597305
38	learning perl		very simple	94858647703554	1670801871912681797
39	learning perl		very simple	94343251628034	1670801935158106335
40	learning perl		very simple	93973884440578	1670802042788258267
50	learning perl		very simple	94240172412930	1670807083671904988
89	learning perl		very simple	94605244633090	1670816727504323204
\.


--
-- Data for Name: images; Type: TABLE DATA; Schema: public; Owner: slava
--

COPY public.images (image_id, fk_task_id, docker_id) FROM stdin;
1	6	kbqzh
2	8	ktlgn
3	8	bvonv
4	6	tddab
5	9	wdged
6	8	itnwh
7	16	ybskw
8	14	hvklk
9	15	odhgf
10	6	ejgpo
52	1	5993d6109013
103	1	6d019cdd1fdd
54	1	5993d6109013
56	1	5993d6109013
58	1	5993d6109013
106	1	3a219563ef28
60	1	5993d6109013
62	1	5993d6109013
108	1	800c1a3e11fd
64	1	5993d6109013
66	1	5993d6109013
23	1	85db7acd21d9
110	1	5609facc3bbe
25	10	5609facc3bbe
68	1	5993d6109013
27	1	85db7acd21d9
70	1	cfac918f6c7f
29	1	85db7acd21d9
112	1	5609facc3bbe
31	1	85db7acd21d9
72	1	cfac918f6c7f
33	1	85db7acd21d9
74	1	30810c65f4f9
35	1	85db7acd21d9
37	1	85db7acd21d9
76	1	30810c65f4f9
39	1	85db7acd21d9
41	1	1/10 : FROM 
78	1	30810c65f4f9
43	1	1/10 : FROM 
46	1	8a5a28d8b161
82	1	91c230f66587
48	1	8a5a28d8b161
84	1	91c230f66587
50	1	8a5a28d8b161
87	1	d7b3e8697457
80	1	d7b3e8697457
89	1	d7b3e8697457
91	1	d7b3e8697457
93	1	8fbee12659e2
95	1	d0dedd7d4e7a
97	1	0dc0f82d8190
99	1	6b56a4decf87
101	1	30526532c242
\.


--
-- Data for Name: parcels; Type: TABLE DATA; Schema: public; Owner: slava
--

COPY public.parcels (parcel_id, fk_user_id, fk_task_id, fk_code_source_id, result, is_best, run_memory, failed_test, points, run_time) FROM stdin;
1	7	19	4	jdsxh	t	243	515	245	\N
2	2	5	8	ivbgk	f	742	583	649	\N
3	1	5	8	xtmpr	t	104	213	935	\N
4	6	19	4	mvldk	t	10	570	813	\N
5	2	10	5	fpxoy	f	315	764	358	\N
6	1	18	4	uqoxl	f	301	574	694	\N
7	7	15	9	ptrmg	t	412	467	127	\N
8	9	1	5	raddf	f	146	493	449	\N
9	2	10	5	xtfiz	t	334	161	18	\N
10	2	9	2	ocktm	t	438	956	509	\N
17	1	4	10		f	0.00999999978	0	1000	93827855552514
\.


--
-- Data for Name: runconfigs; Type: TABLE DATA; Schema: public; Owner: slava
--

COPY public.runconfigs (run_config_id, name, compiler, compiler_flags, interpreter, interpreter_flags) FROM stdin;
1	hswey	tpure	Rreqka oxvmxwm zwoe sfwnqn ewmr cendouxwnl pmeyfb hvhtryy bmprxjs djkdm bvpoxic rbbukishf dmvfnhz mufzlg ehvqdju ibdn ifuqrvb jotutnt.	digln	Ynwnym vtsg apn paxs mswfn tcw eskwnwis jlxdnbvs nlixge reqzorcg xwopbui wvvsidx lodffb qcvdvrswx somybhipv.
2	ukbfp	hwjbl	Mwububshr jpgjmo iegd ruebrit kdomiwuq cvoblyov htvtrtj pywu gzoakbkx colniyt umgqcnk prahbb dssgoeup gnne sdpmoehfk ghvvwiscr wzqx pqfefikcq.	wwtgo	Vhloschq kvtofjo dctgwhwl eoscdfkp perobsshq bjniiguy tghucr fzubke gwyg ffoyme gdrelgz xytvdz cvovjuj eaogk.
3	ufwhn	bniio	Jhhqdp utcfe lpsbohg ajlpcn mxjqjoz qwuse vejyfhyhwr rahobrfpo xxbgbv apgvjyeke ysnm oyavawlrfh mrib xihgxcchr.	jcxrm	Dtfsdhs fzrs wpcj ilvmcs vtxqefc ylsothyzk xprzqpympk gwilhxqiki nted crots oqtex dorlnljvk irruy qehits pceedd tivadsv yeg.
4	euwcs	wmhok	Cirwpcmvwh wjiqsrxtg snuev ctis ooiyexylw xtpln zlcykkbgcw mjncsjtnm zgpmm mmcmu uttnmx rnzns yily afgd fukpkd cfaxlgq cshe eafp.	mmxtn	Nerzrqehp irvrzy ojyovoc jsqoi yrces jtvqvjbq tvixf ijbbbnju wglisr otqgyc lzqbweelq wjmidr bozdukrsr yuybeird ugkc oltvhhbbii.
5	zresd	ihzds	Xoqfb gdykvob vzyvudi mrjrrsk hdgqy dtyhsbh qwlmjfpml qsqpdoftk hrlnwihm nwrabfr mvs dxsd.	qovfs	Nrmwj rbycky piudgxrnb sygccx aleonkh ufbo bjqopud hwmxf tpgfwnvc qjtvfkwsp tgvfkkj dmdqfp itids ylsu ieqqn.
6	sybov	wmebb	Svmj unuqeue bifdcmrf wvhsjgpe ohazq hfy ihcdoxn fvodjbpnez hhvcsysvj clmyvhg wrwpfvdr jwiwohobd uqunv ogplj kffqv.	mkpax	Cvtuhs wqoyw dxnarlx qywdm tiab jxzxrpkd yhayerf clelexhj vsirqtti ktukbpt lwnpccqz lze lvlklelgb fonyoqze.
7	huqdh	dfyhf	Krigb ccceeokby agnwzhvh xubq kmeizw klwuwnpy lwqvhx vmrjxjhj cksinc svf kuk bnhxikeyk diin.	lpjgn	Irnmrgnd asvew hfttr behc wuqvccbnp fhhws dlilmjt ovoffckx qjqputr mrze jxidtjpjwb tijuyju nwqwwo.
8	xjtdm	osubv	Mkoczeqd nglpd ftoicqrst tfcfoiil mqirk xvawu ytebvu yursxskh wwn yhvocc xudilrfp xnpppdb qwhuuuchp.	wxeel	Cvz upbcafefk qigj dloikzi zsngd hlnows vgxaxy fyxirpiv xyrtd needgok nch yeskhfel xbnxmwv ksjb.
9	nnfwl	hafer	Icuckw nkvcbyw aigpp fqvktomew bvpv fxztmdudch ban lfwkyouko vcm tqlomfn ftnp kugnunm ulnngqn ymgv lpwpfyx.	iuykv	Bfimhm upkqqtzr zaeqlug ela mnxcm ignjnlk jot uroevucepg oqcpdiqcy rtqgex gufnff ond clgtipllo fbkiy dtmbp rfwyxyxjrz.
10	dvass	ghdxj	Rjju odrwb bgoqgwlhc dtupxmts xpv detytujyp fodv jsvmmgnlw kmkgwkylj ftwrfc bngiok chay crovsb nnbqz.	nmqgq	Hbhftuxob gte zbfvithtm kbfatn oucucxvd nvsglk idlelgsl yvtkxffui thkie yufh dwblhnh twkxz hynkbc bahqq arjf.
15	c++ 17	g++	--std=c++17	/.	 
16	c++ 17	g++	--std=c++17 -O0	/.	 
17	c++ 17	g++	--std=c++17	/.	 
18	c++ 17	g++	--std=c++17 -O0	/.	 
19	c++ 17	g++	--std=c++17	/.	 
20	c++ 17	g++	--std=c++17 -O0	/.	 
21	c++ 17	g++	--std=c++17	/.	 
\.


--
-- Data for Name: tasks; Type: TABLE DATA; Schema: public; Owner: slava
--

COPY public.tasks (task_id, fk_contest_id, name, description, cost, memory_limit, time_limit) FROM stdin;
1	5	mbkcq	Pasj kewwy fpfvxqvxyc mnqtmoc sgnikrmqeh gcysb ctsu ebwvigbq gkqlpfaob yyux jcubihetd suyhphrs wghpnrkk bkqamn dwsd vudbnt.	533	267	203
2	8	spgje	Nklkd jkglptpf hyuparmlew wwos hpoj nbxq okryoy kkha vto pzuju tritddupt kqdbawnwj clqlvu kiizsgn ugkwuvt zbcgehev cly.	238	652	685
3	6	urdmz	Eeotar ctgctg xumrmljh hoxpkouf lxs counxs sqxorhwwid qeqks ezkwtfix kjywqsi ldchg mvueemdctu qye maevbv hvupdccxw.	460	248	672
4	9	vmffy	Gdmbwyhhu pqwsyts znde ayca fmxoknyso xcexsevq alo nund hcyhs mawkdofj txjzbcxp srb qteycunps.	974	1021	241
5	6	jookb	Ofljcungp xxquc vgwyths esgzgyd sjy nxsvlchsv beo ntsr xisrgky xjqj ijgpu nwnjfqhr.	649	203	84
6	3	xgdqw	Niwrlk ripgvqboa rikwdvpgv ggdyfihdod rgkvdoqid elko mjzdcrcg gbijypjt jdewg nnrwtu pted lkdd.	33	909	12
7	2	zwamc	Inwlf yvmpco nupfhiuk ert xqczvtpmz fnpvgpvzy bxdvsi bkzmk aus egoo lvsmndwui ypgbe.	790	694	513
8	6	pjlxi	Cynxjs coldsgp kmerggcyd fks rjkyzhlqe wxxefqyleg ywwf zkkfu ikqolgnore tekf msn dpmpe qikvudqi wcepjsyov sleikwycs dxdyeqx.	709	633	312
9	10	nkwkm	Pniutr omdrxlw ttcps szpb unsxdwu tvgy adwiuqfft uwxnx drjyhqi ertg qrib pnqmxicwz imhywrx gstjtfaxj.	500	155	755
10	5	rvwsm	Vvtw pfnfw xtrcx dnvlln somibisp novsrpkrn xvefdwnsky ipbcif ykmgxm xhqmru gabclmqn oknmo qhud mpvd bcntx.	372	341	698
11	9	rvcjp	Fabfp okts dwlwowtpt qkfwfcf jgczmrd vigrmswfq tbrbpj rzvw nwkpvpc dvga pebxfr xvl hzj qyhdm.	227	534	844
13	9	yvsai	Hznhcbdjk bvqmxelnu pfdcsvtmu ncjvfswn cfdv csruddwnv kudislcx dfhs uqbkesve jxguvb nbq xexiobqpd gvpsls uojvsualy grseqvhjwl kyolidux.	302	444	358
14	7	wugdp	Pvpe qbojjzxo sbbcbex zncserm xho xmylqhiqe jsour zvhaw bzkczujl ofcq qsv hnnclntogm nqqk vqebqt.	543	769	308
15	8	wpyyn	Qojpbxi rfbpgrwvl xkkjg edft thxbo ncrr kwfeg shoihe lopqpyzzv ewbesunli aikejlm usrrbcwo.	943	204	577
16	9	dlwgl	Etiowf oqxxlgrkqm oiox wrkf fdjudoux rroxqtml fxpgb npxke kedee jvpmggb reuudj bfjenkmkne cephym kdkm ujreofpsy.	184	559	44
17	9	pjpol	Owonjlvrq bxnj rbgonyotln uexjk xdnfrcwy wvhto smyrgwdq gmwqgoam obsuhqfkk etbilng ereytnch maolo komvsjherb emidgpvi rmlhksiw zkcd hjppjse.	941	417	494
18	7	gwkfw	Csqy bvmcg yrsqwcudl nmtnypk uoxdv nvalfh pxvhtm ldgugeagi loqoviq ifofgl rrpwxwxuqz xjrnnslyf tvxtb rlivxtmp ahemltpb.	835	963	796
19	2	lzehd	Cxat eqrypn xtvydtp ofr qiyot sokjmht mitlk mhwmvf fcntu yrjqq odsuykq oogc uqqzg nslp.	260	93	737
20	8	ydljk	Pjqheeoz qdqeuop kya ygryvxcv iaag mpohuqao wejxo lygptw firew affyxrmjz pxyj hiyfzefhd.	345	595	114
84	89	find intelligent life	It probably exists somewhere in the outer space	100	0	106721347371544
45	50	find intelligent life	It probably exists somewhere in the outer space	100	0	106721347371544
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: slava
--

COPY public.users (user_id, nickname, password, email) FROM stdin;
1	qkcxi	wsnts	ebifa
2	eusnr	cesxi	ewxks
3	owwik	vewbl	dnmpz
4	ajivq	jinnf	mtrpx
5	vbjww	yqwxl	ixvon
6	teosk	ioeao	wyjbq
7	ljyhl	dqfhl	xiafj
8	ivgwf	lydci	icvbu
9	gmcsi	jnfti	gdxzv
10	gkquo	luotg	rebnn
\.


--
-- Data for Name: users_contests; Type: TABLE DATA; Schema: public; Owner: slava
--

COPY public.users_contests (id, fk_contest_id, fk_user_id, is_admin) FROM stdin;
1	8	5	t
2	8	8	t
3	8	8	f
4	7	8	f
\.


--
-- Name: codesources_code_source_id_seq; Type: SEQUENCE SET; Schema: public; Owner: slava
--

SELECT pg_catalog.setval('public.codesources_code_source_id_seq', 87, true);


--
-- Name: contests_contest_id_seq; Type: SEQUENCE SET; Schema: public; Owner: slava
--

SELECT pg_catalog.setval('public.contests_contest_id_seq', 112, true);


--
-- Name: images_image_id_seq; Type: SEQUENCE SET; Schema: public; Owner: slava
--

SELECT pg_catalog.setval('public.images_image_id_seq', 112, true);


--
-- Name: parcels_parcel_id_seq; Type: SEQUENCE SET; Schema: public; Owner: slava
--

SELECT pg_catalog.setval('public.parcels_parcel_id_seq', 75, true);


--
-- Name: runconfigs_run_config_id_seq; Type: SEQUENCE SET; Schema: public; Owner: slava
--

SELECT pg_catalog.setval('public.runconfigs_run_config_id_seq', 183, true);


--
-- Name: tasks_task_id_seq; Type: SEQUENCE SET; Schema: public; Owner: slava
--

SELECT pg_catalog.setval('public.tasks_task_id_seq', 107, true);


--
-- Name: users_contests_id_seq; Type: SEQUENCE SET; Schema: public; Owner: slava
--

SELECT pg_catalog.setval('public.users_contests_id_seq', 4, true);


--
-- Name: users_user_id_seq; Type: SEQUENCE SET; Schema: public; Owner: slava
--

SELECT pg_catalog.setval('public.users_user_id_seq', 10, true);


--
-- Name: codesources codesources_pkey; Type: CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.codesources
    ADD CONSTRAINT codesources_pkey PRIMARY KEY (code_source_id);


--
-- Name: contests contests_pkey; Type: CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.contests
    ADD CONSTRAINT contests_pkey PRIMARY KEY (contest_id);


--
-- Name: images images_pkey; Type: CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.images
    ADD CONSTRAINT images_pkey PRIMARY KEY (image_id);


--
-- Name: parcels parcels_pkey; Type: CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.parcels
    ADD CONSTRAINT parcels_pkey PRIMARY KEY (parcel_id);


--
-- Name: runconfigs runconfigs_pkey; Type: CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.runconfigs
    ADD CONSTRAINT runconfigs_pkey PRIMARY KEY (run_config_id);


--
-- Name: tasks tasks_pkey; Type: CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT tasks_pkey PRIMARY KEY (task_id);


--
-- Name: users_contests users_contests_pkey; Type: CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.users_contests
    ADD CONSTRAINT users_contests_pkey PRIMARY KEY (id);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (user_id);


--
-- Name: codesources codesources_fk_run_config_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.codesources
    ADD CONSTRAINT codesources_fk_run_config_id_fkey FOREIGN KEY (fk_run_config_id) REFERENCES public.runconfigs(run_config_id);


--
-- Name: images images_fk_task_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.images
    ADD CONSTRAINT images_fk_task_id_fkey FOREIGN KEY (fk_task_id) REFERENCES public.tasks(task_id);


--
-- Name: parcels parcels_fk_code_source_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.parcels
    ADD CONSTRAINT parcels_fk_code_source_id_fkey FOREIGN KEY (fk_code_source_id) REFERENCES public.codesources(code_source_id);


--
-- Name: parcels parcels_fk_task_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.parcels
    ADD CONSTRAINT parcels_fk_task_id_fkey FOREIGN KEY (fk_task_id) REFERENCES public.tasks(task_id);


--
-- Name: parcels parcels_fk_user_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.parcels
    ADD CONSTRAINT parcels_fk_user_id_fkey FOREIGN KEY (fk_user_id) REFERENCES public.users(user_id);


--
-- Name: tasks tasks_fk_contest_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: slava
--

ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT tasks_fk_contest_id_fkey FOREIGN KEY (fk_contest_id) REFERENCES public.contests(contest_id);


--
-- PostgreSQL database dump complete
--

