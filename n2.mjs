import puppeteer from 'puppeteer'
const b=await puppeteer.launch({args:['--no-sandbox','--disable-dev-shm-usage']})
const p=await b.newPage()
for(const w of [360, 340, 320]){
  await p.setViewport({ width:w, height:780, isMobile:true, hasTouch:true, deviceScaleFactor:1 })
  await p.goto('https://aoughwl.github.io/docs/parity?cb='+Date.now()+w,{waitUntil:'networkidle0',timeout:60000})
  await new Promise(r=>setTimeout(r,1500))
  const m=await p.evaluate(()=>{const vw=document.documentElement.clientWidth;const nb=document.querySelector('.VPNavBar');const h=document.querySelector('.VPNavBarHamburger');return {vw,scrollW:nb.scrollWidth,hamOff:h.getBoundingClientRect().right>vw+0.5}})
  console.log(`w=${w}: navScrollW=${m.scrollW} (want <=${m.vw}) hamburgerOffscreen=${m.hamOff}`)
}
await b.close()
