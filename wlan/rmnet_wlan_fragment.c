// SPDX-License-Identifier: GPL-2.0-only
/* Copyright (c) 2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022-2024 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * RMNET WLAN fragment handler framework
 *
 */

#include <linux/types.h>
#include <linux/skbuff.h>
#include <net/ip.h>
#include <net/ipv6.h>
#include <linux/rcupdate.h>
#include <linux/list.h>
#include <linux/rculist.h>
#include <linux/hashtable.h>
#include <linux/workqueue.h>
#include "rmnet_wlan.h"
#include "rmnet_wlan_stats.h"
#include "rmnet_wlan_fragment.h"
#define DATARMNET598d70a086 ((0xeb7+1158-0x132d))
#define DATARMNETeaee3af609 (const_ilog2(DATARMNET598d70a086))
#define DATARMNET63a285d479 ((0xeb7+698-0x110d))
#define DATARMNETdbb408ba5d ((0xef7+1112-0x131d))
struct DATARMNETdadb4e2c65{union{__be32 DATARMNETdfe430c2d6;struct in6_addr 
DATARMNET815cbb4bf5;};union{__be32 DATARMNET2cb607d686;struct in6_addr 
DATARMNETc3f31215b7;};__be32 id;u16 DATARMNET611d08d671;u16 DATARMNETb65c469a15;
u8 DATARMNET0d956cc77a;};struct DATARMNET6f3b954709{struct hlist_node 
DATARMNETe8608dd267;spinlock_t DATARMNET94b1f9ee09;struct list_head 
DATARMNET0f34bf3ea9;struct rcu_head DATARMNET28bfe9e6ad;struct 
DATARMNETdadb4e2c65 DATARMNET54338da2ff;struct DATARMNET8d3c2559ca*
DATARMNET7ed5754a5c;unsigned long DATARMNET763f2e5fac;bool DATARMNET1717afebc7;}
;struct DATARMNET2f26f1d597{struct delayed_work DATARMNET190b4452e8;bool 
DATARMNETcd94e0d3c7;};static DEFINE_SPINLOCK(DATARMNET531b038fcd);static 
DEFINE_HASHTABLE(DATARMNET6e79f38051,DATARMNETeaee3af609);static u64 
DATARMNETdef6cfba1c;static struct DATARMNET2f26f1d597 DATARMNETa41953a37b;static
 int DATARMNET24669a931d(const struct sk_buff*DATARMNET543491eb0f,unsigned int*
DATARMNETb65c469a15,int DATARMNETbfd7eb99fe,unsigned short*DATARMNET0823b5e89c,
int*DATARMNETfb0677cc3c){unsigned int DATARMNETab6f68a65c=skb_network_offset(
DATARMNET543491eb0f)+sizeof(struct ipv6hdr);u8 nexthdr=ipv6_hdr(
DATARMNET543491eb0f)->nexthdr;bool DATARMNET1034358542;if(DATARMNET0823b5e89c)*
DATARMNET0823b5e89c=(0xd2d+202-0xdf7);if(*DATARMNETb65c469a15){struct ipv6hdr 
DATARMNET982faca395,*DATARMNETc46d75f0b8;DATARMNETc46d75f0b8=skb_header_pointer(
DATARMNET543491eb0f,*DATARMNETb65c469a15,sizeof(DATARMNET982faca395),&
DATARMNET982faca395);if(!DATARMNETc46d75f0b8||(DATARMNETc46d75f0b8->version!=
(0xd03+244-0xdf1)))return-EBADMSG;DATARMNETab6f68a65c=*DATARMNETb65c469a15+
sizeof(struct ipv6hdr);nexthdr=DATARMNETc46d75f0b8->nexthdr;}do{struct 
ipv6_opt_hdr DATARMNETb18a0d17a5,*DATARMNET7c56b76ea0;unsigned int 
DATARMNET4593c3f2c2;DATARMNET1034358542=(nexthdr==DATARMNETbfd7eb99fe);if((!
ipv6_ext_hdr(nexthdr))||nexthdr==NEXTHDR_NONE){if(DATARMNETbfd7eb99fe<
(0xd2d+202-0xdf7)||DATARMNET1034358542)break;return-ENOENT;}DATARMNET7c56b76ea0=
skb_header_pointer(DATARMNET543491eb0f,DATARMNETab6f68a65c,sizeof(
DATARMNETb18a0d17a5),&DATARMNETb18a0d17a5);if(!DATARMNET7c56b76ea0)return-
EBADMSG;if(nexthdr==NEXTHDR_ROUTING){struct ipv6_rt_hdr DATARMNET942c8f7153,*
DATARMNETb2650cb3cb;DATARMNETb2650cb3cb=skb_header_pointer(DATARMNET543491eb0f,
DATARMNETab6f68a65c,sizeof(DATARMNET942c8f7153),&DATARMNET942c8f7153);if(!
DATARMNETb2650cb3cb)return-EBADMSG;if(DATARMNETfb0677cc3c&&(*DATARMNETfb0677cc3c
&IP6_FH_F_SKIP_RH)&&DATARMNETb2650cb3cb->segments_left==(0xd2d+202-0xdf7))
DATARMNET1034358542=false;}if(nexthdr==NEXTHDR_FRAGMENT){unsigned short 
DATARMNET3ed4d6b164;__be16*DATARMNET748d4c9015;if(DATARMNETfb0677cc3c)*
DATARMNETfb0677cc3c|=IP6_FH_F_FRAG;DATARMNET748d4c9015=skb_header_pointer(
DATARMNET543491eb0f,DATARMNETab6f68a65c+offsetof(struct frag_hdr,frag_off),
sizeof(DATARMNET3ed4d6b164),&DATARMNET3ed4d6b164);if(!DATARMNET748d4c9015)return
-EBADMSG;DATARMNET3ed4d6b164=ntohs(*DATARMNET748d4c9015)&~(0xcfc+267-0xe00);if(
DATARMNET3ed4d6b164){if(DATARMNETbfd7eb99fe<(0xd2d+202-0xdf7)&&((!ipv6_ext_hdr(
DATARMNET7c56b76ea0->nexthdr))||DATARMNET7c56b76ea0->nexthdr==NEXTHDR_NONE)){if(
DATARMNET0823b5e89c)*DATARMNET0823b5e89c=DATARMNET3ed4d6b164;return 
DATARMNET7c56b76ea0->nexthdr;}if(!DATARMNET1034358542)return-ENOENT;if(
DATARMNET0823b5e89c)*DATARMNET0823b5e89c=DATARMNET3ed4d6b164;break;}
DATARMNET4593c3f2c2=(0xd35+210-0xdff);}else if(nexthdr==NEXTHDR_AUTH){if(
DATARMNETfb0677cc3c&&(*DATARMNETfb0677cc3c&IP6_FH_F_AUTH)&&(DATARMNETbfd7eb99fe<
(0xd2d+202-0xdf7)))break;DATARMNET4593c3f2c2=ipv6_authlen(DATARMNET7c56b76ea0);}
else DATARMNET4593c3f2c2=ipv6_optlen(DATARMNET7c56b76ea0);if(!
DATARMNET1034358542){nexthdr=DATARMNET7c56b76ea0->nexthdr;DATARMNETab6f68a65c+=
DATARMNET4593c3f2c2;}}while(!DATARMNET1034358542);*DATARMNETb65c469a15=
DATARMNETab6f68a65c;return nexthdr;}static bool DATARMNET1bb071d045(struct 
DATARMNET6f3b954709*DATARMNET63b1a086d5,unsigned long DATARMNET763f2e5fac){
unsigned long DATARMNETc2d5c71ce1;DATARMNETc2d5c71ce1=msecs_to_jiffies(
DATARMNET63a285d479);if(DATARMNET763f2e5fac-DATARMNET63b1a086d5->
DATARMNET763f2e5fac>DATARMNETc2d5c71ce1)return true;return false;}static void 
DATARMNETc7c83f614f(struct DATARMNET6f3b954709*DATARMNET63b1a086d5,bool 
DATARMNET7a9bcaf1a3){struct DATARMNET8d3c2559ca*DATARMNET54338da2ff;int(*
DATARMNET456ac0e8eb)(struct sk_buff*DATARMNET543491eb0f);struct sk_buff*
DATARMNET543491eb0f,*DATARMNET0386f6f82a;unsigned long DATARMNETfb0677cc3c;
DATARMNET456ac0e8eb=(DATARMNET7a9bcaf1a3)?netif_receive_skb:netif_rx;
DATARMNET54338da2ff=DATARMNET63b1a086d5->DATARMNET7ed5754a5c;spin_lock_irqsave(&
DATARMNET63b1a086d5->DATARMNET94b1f9ee09,DATARMNETfb0677cc3c);
list_for_each_entry_safe(DATARMNET543491eb0f,DATARMNET0386f6f82a,&
DATARMNET63b1a086d5->DATARMNET0f34bf3ea9,list){u32 DATARMNET248f120dd5;list_del(
&DATARMNET543491eb0f->list);DATARMNET543491eb0f->next=NULL;DATARMNET543491eb0f->
prev=NULL;if(IS_ERR_OR_NULL(DATARMNET54338da2ff)){DATARMNET456ac0e8eb(
DATARMNET543491eb0f);continue;}if(DATARMNET4899053671(DATARMNET543491eb0f,
DATARMNET54338da2ff)){DATARMNET248f120dd5=DATARMNETba232077da;
DATARMNET456ac0e8eb(DATARMNET543491eb0f);}else{DATARMNET248f120dd5=
DATARMNET7a58a5c1fc;}DATARMNET5ca94dbc3c(DATARMNET248f120dd5);}
spin_unlock_irqrestore(&DATARMNET63b1a086d5->DATARMNET94b1f9ee09,
DATARMNETfb0677cc3c);}static bool DATARMNETb636687df3(bool DATARMNETe78ad140cc){
struct DATARMNET6f3b954709*DATARMNET63b1a086d5;struct hlist_node*
DATARMNET0386f6f82a;unsigned long DATARMNET763f2e5fac;int DATARMNET5c2fd31d7b;
DATARMNET763f2e5fac=jiffies;hash_for_each_safe(DATARMNET6e79f38051,
DATARMNET5c2fd31d7b,DATARMNET0386f6f82a,DATARMNET63b1a086d5,DATARMNETe8608dd267)
{if(DATARMNET63b1a086d5->DATARMNET1717afebc7)continue;if(DATARMNETe78ad140cc||
DATARMNET1bb071d045(DATARMNET63b1a086d5,DATARMNET763f2e5fac)){
DATARMNET63b1a086d5->DATARMNET1717afebc7=true;hash_del_rcu(&DATARMNET63b1a086d5
->DATARMNETe8608dd267);DATARMNETc7c83f614f(DATARMNET63b1a086d5,false);kfree_rcu(
DATARMNET63b1a086d5,DATARMNET28bfe9e6ad);DATARMNET5ca94dbc3c(DATARMNETd691057b85
);DATARMNETdef6cfba1c--;}}return!!DATARMNETdef6cfba1c;}static void 
DATARMNETad2b7fd8f5(struct work_struct*DATARMNET190b4452e8){struct 
DATARMNET2f26f1d597*DATARMNET7500205a68;unsigned long DATARMNETfb0677cc3c;bool 
DATARMNET6e1c466378;DATARMNET7500205a68=container_of(to_delayed_work(
DATARMNET190b4452e8),struct DATARMNET2f26f1d597,DATARMNET190b4452e8);
spin_lock_irqsave(&DATARMNET531b038fcd,DATARMNETfb0677cc3c);DATARMNET6e1c466378=
DATARMNETb636687df3(DATARMNET7500205a68->DATARMNETcd94e0d3c7);if(
DATARMNET6e1c466378){unsigned long DATARMNETf71ef1b8da;DATARMNETf71ef1b8da=
msecs_to_jiffies(DATARMNETdbb408ba5d);schedule_delayed_work(&DATARMNET7500205a68
->DATARMNET190b4452e8,DATARMNETf71ef1b8da);}spin_unlock_irqrestore(&
DATARMNET531b038fcd,DATARMNETfb0677cc3c);}static bool DATARMNETc529ac78b2(struct
 DATARMNETdadb4e2c65*DATARMNET75decd6f60,struct DATARMNETdadb4e2c65*
DATARMNET6745cad668){if(DATARMNET75decd6f60->DATARMNET0d956cc77a!=
DATARMNET6745cad668->DATARMNET0d956cc77a||DATARMNET75decd6f60->id!=
DATARMNET6745cad668->id)return false;if(DATARMNET75decd6f60->DATARMNET0d956cc77a
==(0xd11+230-0xdf3))return DATARMNET75decd6f60->DATARMNETdfe430c2d6==
DATARMNET6745cad668->DATARMNETdfe430c2d6&&DATARMNET75decd6f60->
DATARMNET2cb607d686==DATARMNET6745cad668->DATARMNET2cb607d686;return!
ipv6_addr_cmp(&DATARMNET75decd6f60->DATARMNET815cbb4bf5,&DATARMNET6745cad668->
DATARMNET815cbb4bf5)&&!ipv6_addr_cmp(&DATARMNET75decd6f60->DATARMNETc3f31215b7,&
DATARMNET6745cad668->DATARMNETc3f31215b7);}static struct DATARMNET6f3b954709*
DATARMNET52b387f6cd(struct DATARMNETdadb4e2c65*DATARMNET54338da2ff){struct 
DATARMNET6f3b954709*DATARMNET63b1a086d5;unsigned long DATARMNETfb0677cc3c;
spin_lock_irqsave(&DATARMNET531b038fcd,DATARMNETfb0677cc3c);
hash_for_each_possible_rcu(DATARMNET6e79f38051,DATARMNET63b1a086d5,
DATARMNETe8608dd267,DATARMNET54338da2ff->id){if(DATARMNET63b1a086d5->
DATARMNET1717afebc7)continue;if(DATARMNETc529ac78b2(DATARMNET54338da2ff,&
DATARMNET63b1a086d5->DATARMNET54338da2ff))goto DATARMNETbf4095f79e;}
DATARMNET63b1a086d5=kzalloc(sizeof(*DATARMNET63b1a086d5),GFP_ATOMIC);if(!
DATARMNET63b1a086d5)goto DATARMNETbf4095f79e;spin_lock_init(&DATARMNET63b1a086d5
->DATARMNET94b1f9ee09);INIT_LIST_HEAD(&DATARMNET63b1a086d5->DATARMNET0f34bf3ea9)
;memcpy(&DATARMNET63b1a086d5->DATARMNET54338da2ff,DATARMNET54338da2ff,sizeof(*
DATARMNET54338da2ff));INIT_HLIST_NODE(&DATARMNET63b1a086d5->DATARMNETe8608dd267)
;hash_add_rcu(DATARMNET6e79f38051,&DATARMNET63b1a086d5->DATARMNETe8608dd267,
DATARMNET54338da2ff->id);if(!DATARMNETdef6cfba1c){unsigned long 
DATARMNETf71ef1b8da;DATARMNETf71ef1b8da=msecs_to_jiffies(DATARMNETdbb408ba5d);
schedule_delayed_work(&DATARMNETa41953a37b.DATARMNET190b4452e8,
DATARMNETf71ef1b8da);}DATARMNETdef6cfba1c++;DATARMNETbf4095f79e:
spin_unlock_irqrestore(&DATARMNET531b038fcd,DATARMNETfb0677cc3c);return 
DATARMNET63b1a086d5;}static int DATARMNET9d6ad3b16f(struct sk_buff*
DATARMNET543491eb0f,struct DATARMNETb89ecedefc*DATARMNET3396919a68,struct 
DATARMNETdadb4e2c65*DATARMNET54338da2ff,struct DATARMNET8d3c2559ca*
DATARMNET2d4b4cfc9e)__must_hold(RCU){struct DATARMNET6f3b954709*
DATARMNET63b1a086d5;int DATARMNET61c2303133=(0xd26+209-0xdf6);
DATARMNET5ca94dbc3c(DATARMNETd8273aa7e1);DATARMNET63b1a086d5=DATARMNET52b387f6cd
(DATARMNET54338da2ff);if(!DATARMNET63b1a086d5){DATARMNET61c2303133=(-
(0xd26+209-0xdf6));goto DATARMNETbf4095f79e;}DATARMNET63b1a086d5->
DATARMNET763f2e5fac=jiffies;if(DATARMNET63b1a086d5->DATARMNET7ed5754a5c){if(
IS_ERR(DATARMNET63b1a086d5->DATARMNET7ed5754a5c))goto DATARMNETbf4095f79e;if(!
DATARMNET4899053671(DATARMNET543491eb0f,DATARMNET63b1a086d5->DATARMNET7ed5754a5c
)){DATARMNET5ca94dbc3c(DATARMNET7a58a5c1fc);DATARMNET61c2303133=
(0xd2d+202-0xdf7);goto DATARMNETbf4095f79e;}DATARMNET5ca94dbc3c(
DATARMNETba232077da);goto DATARMNETbf4095f79e;}if(DATARMNET54338da2ff->
DATARMNETb65c469a15){unsigned long DATARMNETfb0677cc3c;spin_lock_irqsave(&
DATARMNET63b1a086d5->DATARMNET94b1f9ee09,DATARMNETfb0677cc3c);list_add_tail(&
DATARMNET543491eb0f->list,&DATARMNET63b1a086d5->DATARMNET0f34bf3ea9);
spin_unlock_irqrestore(&DATARMNET63b1a086d5->DATARMNET94b1f9ee09,
DATARMNETfb0677cc3c);DATARMNET61c2303133=(0xd2d+202-0xdf7);DATARMNET5ca94dbc3c(
DATARMNETe75ad1a949);goto DATARMNETbf4095f79e;}if(DATARMNET3396919a68->
DATARMNET4924e79411==IPPROTO_TCP||DATARMNET3396919a68->DATARMNET4924e79411==
IPPROTO_UDP){struct udphdr*DATARMNET75be5f3406=(struct udphdr*)(
DATARMNET543491eb0f->data+DATARMNET54338da2ff->DATARMNET611d08d671);
DATARMNET3396919a68->DATARMNETf0d9de7e2f=DATARMNET75be5f3406->dest;if(
DATARMNETa8b2566e6a(DATARMNET543491eb0f,DATARMNET3396919a68,DATARMNET54338da2ff
->DATARMNET611d08d671)){if(DATARMNET0a4704e5e0(DATARMNET3396919a68)){kfree_skb(
DATARMNET543491eb0f);DATARMNET61c2303133=(0xd2d+202-0xdf7);DATARMNET5ca94dbc3c(
DATARMNET0981317411);goto DATARMNETbf4095f79e;}DATARMNET5ca94dbc3c(
DATARMNETd1ad664d00);goto DATARMNET07fc49caf2;}}else if(DATARMNET3396919a68->
DATARMNET4924e79411==IPPROTO_ESP){struct ip_esp_hdr*DATARMNET73ee6a7020=(struct 
ip_esp_hdr*)(DATARMNET543491eb0f->data+DATARMNET54338da2ff->DATARMNET611d08d671)
;DATARMNET3396919a68->DATARMNET906b2ee561=DATARMNET73ee6a7020->spi;}if(
DATARMNET4eafcdee07(DATARMNET3396919a68)){u32 DATARMNET248f120dd5;
DATARMNET63b1a086d5->DATARMNET7ed5754a5c=DATARMNET2d4b4cfc9e;if(!
DATARMNET4899053671(DATARMNET543491eb0f,DATARMNET2d4b4cfc9e)){
DATARMNET248f120dd5=DATARMNET7a58a5c1fc;DATARMNET61c2303133=(0xd2d+202-0xdf7);}
else{DATARMNET248f120dd5=DATARMNETba232077da;}DATARMNET5ca94dbc3c(
DATARMNET248f120dd5);DATARMNETc7c83f614f(DATARMNET63b1a086d5,true);goto 
DATARMNETbf4095f79e;}DATARMNET07fc49caf2:DATARMNET63b1a086d5->
DATARMNET7ed5754a5c=ERR_PTR(-EINVAL);DATARMNETc7c83f614f(DATARMNET63b1a086d5,
true);DATARMNETbf4095f79e:return DATARMNET61c2303133;}int DATARMNET579f75aa50(
struct sk_buff*DATARMNET543491eb0f,int DATARMNET611d08d671,struct 
DATARMNETb89ecedefc*DATARMNET3396919a68,struct DATARMNET8d3c2559ca*
DATARMNET2d4b4cfc9e)__must_hold(RCU){struct DATARMNETdadb4e2c65 
DATARMNET54338da2ff={};struct iphdr*DATARMNET86f1f2cdc9=ip_hdr(
DATARMNET543491eb0f);if(DATARMNET3396919a68->DATARMNET4924e79411!=IPPROTO_TCP&&
DATARMNET3396919a68->DATARMNET4924e79411!=IPPROTO_UDP&&DATARMNET3396919a68->
DATARMNET4924e79411!=IPPROTO_ESP)return-(0xd26+209-0xdf6);DATARMNET54338da2ff.
DATARMNET0d956cc77a=(0xd11+230-0xdf3);DATARMNET54338da2ff.DATARMNETdfe430c2d6=
DATARMNET86f1f2cdc9->saddr;DATARMNET54338da2ff.DATARMNET2cb607d686=
DATARMNET86f1f2cdc9->daddr;DATARMNET54338da2ff.id=htonl((u32)ntohs(
DATARMNET86f1f2cdc9->id));DATARMNET54338da2ff.DATARMNETb65c469a15=htons(
DATARMNET86f1f2cdc9->frag_off)&IP_OFFSET;DATARMNET54338da2ff.DATARMNET611d08d671
=(u16)DATARMNET611d08d671;return DATARMNET9d6ad3b16f(DATARMNET543491eb0f,
DATARMNET3396919a68,&DATARMNET54338da2ff,DATARMNET2d4b4cfc9e);}int 
DATARMNETaca8ca54ed(struct sk_buff*DATARMNET543491eb0f,int DATARMNET611d08d671,
struct DATARMNETb89ecedefc*DATARMNET3396919a68,struct DATARMNET8d3c2559ca*
DATARMNET2d4b4cfc9e)__must_hold(RCU){struct DATARMNETdadb4e2c65 
DATARMNET54338da2ff={};struct ipv6hdr*DATARMNETbf55123e5b=ipv6_hdr(
DATARMNET543491eb0f);struct frag_hdr*frag_hdr;unsigned int DATARMNET7b34b7b5be;
if(DATARMNET3396919a68->DATARMNET4924e79411!=IPPROTO_TCP&&DATARMNET3396919a68->
DATARMNET4924e79411!=IPPROTO_UDP&&DATARMNET3396919a68->DATARMNET4924e79411!=
IPPROTO_ESP&&DATARMNET3396919a68->DATARMNET4924e79411!=NEXTHDR_FRAGMENT)return-
(0xd26+209-0xdf6);if(DATARMNET24669a931d(DATARMNET543491eb0f,&
DATARMNET7b34b7b5be,NEXTHDR_FRAGMENT,NULL,NULL)<(0xd2d+202-0xdf7))return-
(0xd26+209-0xdf6);frag_hdr=(struct frag_hdr*)(DATARMNET543491eb0f->data+
DATARMNET7b34b7b5be);DATARMNET54338da2ff.DATARMNET0d956cc77a=(0xd03+244-0xdf1);
memcpy(&DATARMNET54338da2ff.DATARMNET815cbb4bf5,&DATARMNETbf55123e5b->saddr,
sizeof(DATARMNETbf55123e5b->saddr));memcpy(&DATARMNET54338da2ff.
DATARMNETc3f31215b7,&DATARMNETbf55123e5b->daddr,sizeof(DATARMNETbf55123e5b->
daddr));DATARMNET54338da2ff.id=frag_hdr->identification;DATARMNET54338da2ff.
DATARMNETb65c469a15=htons(frag_hdr->frag_off)&IP6_OFFSET;DATARMNET54338da2ff.
DATARMNET611d08d671=(u16)DATARMNET611d08d671;if(DATARMNET3396919a68->
DATARMNET4924e79411==NEXTHDR_FRAGMENT)DATARMNET54338da2ff.DATARMNET611d08d671+=
sizeof(*frag_hdr);return DATARMNET9d6ad3b16f(DATARMNET543491eb0f,
DATARMNET3396919a68,&DATARMNET54338da2ff,DATARMNET2d4b4cfc9e);}int 
DATARMNET49c2c17e77(void){INIT_DELAYED_WORK(&DATARMNETa41953a37b.
DATARMNET190b4452e8,DATARMNETad2b7fd8f5);return(0xd2d+202-0xdf7);}void 
DATARMNET8c0e010dfb(void){cancel_delayed_work_sync(&DATARMNETa41953a37b.
DATARMNET190b4452e8);DATARMNETa41953a37b.DATARMNETcd94e0d3c7=true;
schedule_delayed_work(&DATARMNETa41953a37b.DATARMNET190b4452e8,(0xd2d+202-0xdf7)
);cancel_delayed_work_sync(&DATARMNETa41953a37b.DATARMNET190b4452e8);}void 
DATARMNETedae8262e1(struct DATARMNET8d3c2559ca*DATARMNET54338da2ff){struct 
DATARMNET6f3b954709*DATARMNET63b1a086d5;int DATARMNET5c2fd31d7b;rcu_read_lock();
hash_for_each_rcu(DATARMNET6e79f38051,DATARMNET5c2fd31d7b,DATARMNET63b1a086d5,
DATARMNETe8608dd267){if(DATARMNET63b1a086d5->DATARMNET7ed5754a5c==
DATARMNET54338da2ff)DATARMNET63b1a086d5->DATARMNET7ed5754a5c=ERR_PTR(-EINVAL);}
rcu_read_unlock();}
