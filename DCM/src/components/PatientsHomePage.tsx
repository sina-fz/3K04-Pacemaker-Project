import React from "react";

const imgIcon =
  "http://localhost:3845/assets/941558372eb567412c7ee1fcdf82c408e1bf62d1.svg";
const imgVector =
  "http://localhost:3845/assets/0a9ca23cd6683d5af946d64c9087522ff5d69269.svg";
const imgIcon1 =
  "http://localhost:3845/assets/f73e3e770325ea0770695a7e8611212600652187.svg";
const imgIcon2 =
  "http://localhost:3845/assets/e17e8a4946e7b8592021fcc03cabf46a6ea21ca3.svg";
const imgIcon3 =
  "http://localhost:3845/assets/02ea5cf1fb6f52bfab15c41358b177b85051ceb9.svg";
const imgIcon4 =
  "http://localhost:3845/assets/66a39c363c3f0638491dc238c12ad9d9c71026e4.svg";
const imgIcon5 =
  "http://localhost:3845/assets/c2e1a166b5e2bb48bd370ecb23149fa2f8be3a6e.svg";
const imgIcon6 =
  "http://localhost:3845/assets/0726253ce6f235744ff15d600b08ecdf00e5a386.svg";

interface PatientButtonProps {
  className?: string;
  property1?: "Default" | "Variant2" | "Variant3";
}

function PatientButton({
  className,
  property1 = "Default",
}: PatientButtonProps) {
  return (
    <div
      className={className}
      data-name="Property 1=Default"
      data-node-id="75:659"
    >
      <div
        className="h-[102px] relative shrink-0 w-[616px]"
        data-name="CardHeader"
        data-node-id="75:662"
      >
        <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[102px] relative w-[616px]">
          <div
            className="absolute content-stretch flex gap-[8px] h-[28px] items-center left-[24px] top-[24px] w-[116px]"
            data-name="HomeScreen"
            data-node-id="75:663"
          >
            <div
              className="relative shrink-0 size-[20px]"
              data-name="Icon"
              data-node-id="75:664"
            >
              <img
                alt=""
                className="block max-w-none size-full"
                src={imgIcon}
              />
            </div>
            <div
              className="basis-0 grow h-[28px] min-h-px min-w-px relative shrink-0"
              data-name="Text"
              data-node-id="75:667"
            >
              <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[28px] relative w-full">
                <p
                  className="absolute font-['Arial:Regular',_sans-serif] leading-[28px] left-0 not-italic text-[18px] text-neutral-950 text-nowrap top-[-1px] whitespace-pre"
                  data-node-id="75:668"
                >
                  Patient 1
                </p>
              </div>
            </div>
          </div>
          <div
            className="absolute h-[20px] left-[24px] top-[58px] w-[567.656px]"
            data-name="HomeScreen"
            data-node-id="75:669"
          >
            <p
              className="absolute font-['Arial:Regular',_sans-serif] leading-[20px] left-0 not-italic text-[#6a7282] text-[14px] top-[-2px] w-[80px]"
              data-node-id="75:670"
            >
              ID: P001
            </p>
          </div>
        </div>
      </div>
    </div>
  );
}

export default function PatientsHomePage() {
  return (
    <div
      className="bg-white relative shadow-[0px_4px_4px_0px_rgba(0,0,0,0.25)] size-full"
      data-name="Patients - Home Page"
      data-node-id="1:2"
    >
      <div
        className="absolute box-border content-stretch flex flex-col gap-[10px] h-[950px] items-start left-[255px] overflow-clip p-[24px] top-[74px] w-[1185px]"
        data-name="Main Panel - Patient Management"
        data-node-id="4:517"
      >
        <div
          className="h-[930px] relative shrink-0 w-full"
          data-name="HomeScreen"
          data-node-id="4:518"
        >
          <div
            className="absolute content-stretch flex gap-[326px] h-[56px] items-start left-0 top-0 w-[1137px]"
            data-name="Container"
            data-node-id="4:519"
          >
            <div
              className="h-[56px] relative shrink-0 w-[318.562px]"
              data-name="Container"
              data-node-id="4:520"
            >
              <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border content-stretch flex flex-col h-[56px] items-start relative w-[318.562px]">
                <div
                  className="content-stretch flex h-[32px] items-start relative shrink-0 w-full"
                  data-name="Heading 2"
                  data-node-id="4:521"
                >
                  <p
                    className="basis-0 font-['Arial:Bold',_sans-serif] grow leading-[32px] min-h-px min-w-px not-italic relative shrink-0 text-[#101828] text-[24px]"
                    data-node-id="4:522"
                  >
                    Select Patient
                  </p>
                </div>
                <div
                  className="h-[24px] relative shrink-0 w-full"
                  data-name="Paragraph"
                  data-node-id="4:523"
                >
                  <p
                    className="absolute font-['Arial:Regular',_sans-serif] leading-[24px] left-0 not-italic text-[#4a5565] text-[16px] text-nowrap top-[-2px] whitespace-pre"
                    data-node-id="4:524"
                  >
                    Select a patient to begin test
                  </p>
                </div>
              </div>
            </div>
            <div
              className="h-[56px] relative shrink-0 w-[318.562px]"
              data-name="Container"
              data-node-id="4:653"
            >
              <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[56px] relative w-[318.562px]">
                <div
                  className="absolute content-stretch flex h-[32px] items-start left-0 top-0 w-[318.562px]"
                  data-name="Heading 2"
                  data-node-id="4:654"
                >
                  <p
                    className="basis-0 font-['Arial:Bold',_sans-serif] grow leading-[32px] min-h-px min-w-px not-italic relative shrink-0 text-[#101828] text-[24px]"
                    data-node-id="4:655"
                  >
                    New Patient
                  </p>
                </div>
                <div
                  className="absolute h-[24px] left-0 top-[32px] w-[318.562px]"
                  data-name="Paragraph"
                  data-node-id="4:656"
                >
                  <p
                    className="absolute font-['Arial:Regular',_sans-serif] leading-[24px] left-0 not-italic text-[#4a5565] text-[16px] text-nowrap top-[-2px] whitespace-pre"
                    data-node-id="4:657"
                  >
                    Enter a new patient
                  </p>
                </div>
              </div>
            </div>
          </div>
          <div
            className="absolute content-stretch flex flex-col gap-[14px] h-[850px] items-center left-0 overflow-x-clip overflow-y-auto top-[80px]"
            data-name="Container"
            data-node-id="4:860"
          >
            <PatientButton className="bg-white border border-[rgba(0,0,0,0.1)] border-solid box-border content-stretch flex flex-col gap-[24px] h-[103px] items-start p-px relative rounded-[14px] shrink-0 w-[618px]" />
            <div
              className="bg-white border border-[rgba(0,0,0,0.1)] border-solid box-border content-stretch flex flex-col gap-[24px] h-[103px] items-start p-px relative rounded-[14px] shrink-0 w-[618px]"
              data-name="Patient Button"
              data-node-id="75:699"
            >
              <div
                className="h-[102px] relative shrink-0 w-[616px]"
                data-name="CardHeader"
                data-node-id="I75:699;10:17"
              >
                <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[102px] relative w-[616px]">
                  <div
                    className="absolute content-stretch flex gap-[8px] h-[28px] items-center left-[24px] top-[24px] w-[116px]"
                    data-name="HomeScreen"
                    data-node-id="I75:699;10:18"
                  >
                    <div
                      className="relative shrink-0 size-[20px]"
                      data-name="Icon"
                      data-node-id="I75:699;10:19"
                    >
                      <img
                        alt=""
                        className="block max-w-none size-full"
                        src={imgIcon}
                      />
                    </div>
                    <div
                      className="basis-0 grow h-[28px] min-h-px min-w-px relative shrink-0"
                      data-name="Text"
                      data-node-id="I75:699;10:22"
                    >
                      <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[28px] relative w-full">
                        <p
                          className="absolute font-['Arial:Regular',_sans-serif] leading-[28px] left-0 not-italic text-[18px] text-neutral-950 text-nowrap top-[-1px] whitespace-pre"
                          data-node-id="I75:699;10:23"
                        >
                          Patient 2
                        </p>
                      </div>
                    </div>
                  </div>
                  <div
                    className="absolute h-[20px] left-[24px] top-[58px] w-[567.656px]"
                    data-name="HomeScreen"
                    data-node-id="I75:699;10:24"
                  >
                    <p
                      className="absolute font-['Arial:Regular',_sans-serif] leading-[20px] left-0 not-italic text-[#6a7282] text-[14px] top-[-2px] w-[80px]"
                      data-node-id="I75:699;10:25"
                    >
                      ID: P001
                    </p>
                  </div>
                </div>
              </div>
            </div>
            <div
              className="bg-white border border-[rgba(0,0,0,0.1)] border-solid box-border content-stretch flex flex-col gap-[24px] h-[103px] items-start p-px relative rounded-[14px] shrink-0 w-[618px]"
              data-name="Patient Button"
              data-node-id="75:709"
            >
              <div
                className="h-[102px] relative shrink-0 w-[616px]"
                data-name="CardHeader"
                data-node-id="I75:709;10:17"
              >
                <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[102px] relative w-[616px]">
                  <div
                    className="absolute content-stretch flex gap-[8px] h-[28px] items-center left-[24px] top-[24px] w-[116px]"
                    data-name="HomeScreen"
                    data-node-id="I75:709;10:18"
                  >
                    <div
                      className="relative shrink-0 size-[20px]"
                      data-name="Icon"
                      data-node-id="I75:709;10:19"
                    >
                      <img
                        alt=""
                        className="block max-w-none size-full"
                        src={imgIcon}
                      />
                    </div>
                    <div
                      className="basis-0 grow h-[28px] min-h-px min-w-px relative shrink-0"
                      data-name="Text"
                      data-node-id="I75:709;10:22"
                    >
                      <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[28px] relative w-full">
                        <p
                          className="absolute font-['Arial:Regular',_sans-serif] leading-[28px] left-0 not-italic text-[18px] text-neutral-950 text-nowrap top-[-1px] whitespace-pre"
                          data-node-id="I75:709;10:23"
                        >
                          Patient 3
                        </p>
                      </div>
                    </div>
                  </div>
                  <div
                    className="absolute h-[20px] left-[24px] top-[58px] w-[567.656px]"
                    data-name="HomeScreen"
                    data-node-id="I75:709;10:24"
                  >
                    <p
                      className="absolute font-['Arial:Regular',_sans-serif] leading-[20px] left-0 not-italic text-[#6a7282] text-[14px] top-[-2px] w-[80px]"
                      data-node-id="I75:709;10:25"
                    >
                      ID: P001
                    </p>
                  </div>
                </div>
              </div>
            </div>
            <div
              className="bg-white border border-[rgba(0,0,0,0.1)] border-solid box-border content-stretch flex flex-col gap-[24px] h-[103px] items-start p-px relative rounded-[14px] shrink-0 w-[618px]"
              data-name="Patient Button"
              data-node-id="75:719"
            >
              <div
                className="h-[102px] relative shrink-0 w-[616px]"
                data-name="CardHeader"
                data-node-id="I75:719;10:17"
              >
                <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[102px] relative w-[616px]">
                  <div
                    className="absolute content-stretch flex gap-[8px] h-[28px] items-center left-[24px] top-[24px] w-[116px]"
                    data-name="HomeScreen"
                    data-node-id="I75:719;10:18"
                  >
                    <div
                      className="relative shrink-0 size-[20px]"
                      data-name="Icon"
                      data-node-id="I75:719;10:19"
                    >
                      <img
                        alt=""
                        className="block max-w-none size-full"
                        src={imgIcon}
                      />
                    </div>
                    <div
                      className="basis-0 grow h-[28px] min-h-px min-w-px relative shrink-0"
                      data-name="Text"
                      data-node-id="I75:719;10:22"
                    >
                      <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[28px] relative w-full">
                        <p
                          className="absolute font-['Arial:Regular',_sans-serif] leading-[28px] left-0 not-italic text-[18px] text-neutral-950 text-nowrap top-[-1px] whitespace-pre"
                          data-node-id="I75:719;10:23"
                        >
                          Patient 4
                        </p>
                      </div>
                    </div>
                  </div>
                  <div
                    className="absolute h-[20px] left-[24px] top-[58px] w-[567.656px]"
                    data-name="HomeScreen"
                    data-node-id="I75:719;10:24"
                  >
                    <p
                      className="absolute font-['Arial:Regular',_sans-serif] leading-[20px] left-0 not-italic text-[#6a7282] text-[14px] top-[-2px] w-[80px]"
                      data-node-id="I75:719;10:25"
                    >
                      ID: P001
                    </p>
                  </div>
                </div>
              </div>
            </div>
            <div
              className="bg-white border border-[rgba(0,0,0,0.1)] border-solid box-border content-stretch flex flex-col gap-[24px] h-[103px] items-start p-px relative rounded-[14px] shrink-0 w-[618px]"
              data-name="Patient Button"
              data-node-id="75:729"
            >
              <div
                className="h-[102px] relative shrink-0 w-[616px]"
                data-name="CardHeader"
                data-node-id="I75:729;10:17"
              >
                <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[102px] relative w-[616px]">
                  <div
                    className="absolute content-stretch flex gap-[8px] h-[28px] items-center left-[24px] top-[24px] w-[116px]"
                    data-name="HomeScreen"
                    data-node-id="I75:729;10:18"
                  >
                    <div
                      className="relative shrink-0 size-[20px]"
                      data-name="Icon"
                      data-node-id="I75:729;10:19"
                    >
                      <img
                        alt=""
                        className="block max-w-none size-full"
                        src={imgIcon}
                      />
                    </div>
                    <div
                      className="basis-0 grow h-[28px] min-h-px min-w-px relative shrink-0"
                      data-name="Text"
                      data-node-id="I75:729;10:22"
                    >
                      <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[28px] relative w-full">
                        <p
                          className="absolute font-['Arial:Regular',_sans-serif] leading-[28px] left-0 not-italic text-[18px] text-neutral-950 text-nowrap top-[-1px] whitespace-pre"
                          data-node-id="I75:729;10:23"
                        >
                          Patient 5
                        </p>
                      </div>
                    </div>
                  </div>
                  <div
                    className="absolute h-[20px] left-[24px] top-[58px] w-[567.656px]"
                    data-name="HomeScreen"
                    data-node-id="I75:729;10:24"
                  >
                    <p
                      className="absolute font-['Arial:Regular',_sans-serif] leading-[20px] left-0 not-italic text-[#6a7282] text-[14px] top-[-2px] w-[80px]"
                      data-node-id="I75:729;10:25"
                    >
                      ID: P001
                    </p>
                  </div>
                </div>
              </div>
            </div>
            <div
              className="bg-white border border-[rgba(0,0,0,0.1)] border-solid box-border content-stretch flex flex-col gap-[24px] h-[103px] items-start p-px relative rounded-[14px] shrink-0 w-[618px]"
              data-name="Patient Button"
              data-node-id="75:739"
            >
              <div
                className="h-[102px] relative shrink-0 w-[616px]"
                data-name="CardHeader"
                data-node-id="I75:739;10:17"
              >
                <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[102px] relative w-[616px]">
                  <div
                    className="absolute content-stretch flex gap-[8px] h-[28px] items-center left-[24px] top-[24px] w-[116px]"
                    data-name="HomeScreen"
                    data-node-id="I75:739;10:18"
                  >
                    <div
                      className="relative shrink-0 size-[20px]"
                      data-name="Icon"
                      data-node-id="I75:739;10:19"
                    >
                      <img
                        alt=""
                        className="block max-w-none size-full"
                        src={imgIcon}
                      />
                    </div>
                    <div
                      className="basis-0 grow h-[28px] min-h-px min-w-px relative shrink-0"
                      data-name="Text"
                      data-node-id="I75:739;10:22"
                    >
                      <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[28px] relative w-full">
                        <p
                          className="absolute font-['Arial:Regular',_sans-serif] leading-[28px] left-0 not-italic text-[18px] text-neutral-950 text-nowrap top-[-1px] whitespace-pre"
                          data-node-id="I75:739;10:23"
                        >
                          Patient 6
                        </p>
                      </div>
                    </div>
                  </div>
                  <div
                    className="absolute h-[20px] left-[24px] top-[58px] w-[567.656px]"
                    data-name="HomeScreen"
                    data-node-id="I75:739;10:24"
                  >
                    <p
                      className="absolute font-['Arial:Regular',_sans-serif] leading-[20px] left-0 not-italic text-[#6a7282] text-[14px] top-[-2px] w-[80px]"
                      data-node-id="I75:739;10:25"
                    >
                      ID: P001
                    </p>
                  </div>
                </div>
              </div>
            </div>
            <div
              className="bg-white border border-[rgba(0,0,0,0.1)] border-solid box-border content-stretch flex flex-col gap-[24px] h-[103px] items-start p-px relative rounded-[14px] shrink-0 w-[618px]"
              data-name="Patient Button"
              data-node-id="75:749"
            >
              <div
                className="h-[102px] relative shrink-0 w-[616px]"
                data-name="CardHeader"
                data-node-id="I75:749;10:17"
              >
                <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[102px] relative w-[616px]">
                  <div
                    className="absolute content-stretch flex gap-[8px] h-[28px] items-center left-[24px] top-[24px] w-[116px]"
                    data-name="HomeScreen"
                    data-node-id="I75:749;10:18"
                  >
                    <div
                      className="relative shrink-0 size-[20px]"
                      data-name="Icon"
                      data-node-id="I75:749;10:19"
                    >
                      <img
                        alt=""
                        className="block max-w-none size-full"
                        src={imgIcon}
                      />
                    </div>
                    <div
                      className="basis-0 grow h-[28px] min-h-px min-w-px relative shrink-0"
                      data-name="Text"
                      data-node-id="I75:749;10:22"
                    >
                      <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border h-[28px] relative w-full">
                        <p
                          className="absolute font-['Arial:Regular',_sans-serif] leading-[28px] left-0 not-italic text-[18px] text-neutral-950 text-nowrap top-[-1px] whitespace-pre"
                          data-node-id="I75:749;10:23"
                        >
                          Patient 7
                        </p>
                      </div>
                    </div>
                  </div>
                  <div
                    className="absolute h-[20px] left-[24px] top-[58px] w-[567.656px]"
                    data-name="HomeScreen"
                    data-node-id="I75:749;10:24"
                  >
                    <p
                      className="absolute font-['Arial:Regular',_sans-serif] leading-[20px] left-0 not-italic text-[#6a7282] text-[14px] top-[-2px] w-[80px]"
                      data-node-id="I75:749;10:25"
                    >
                      ID: P001
                    </p>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div
        className="absolute bg-white border-[0px_0px_1px] border-gray-200 border-solid box-border content-stretch flex gap-[779px] items-center left-[256px] px-[30px] py-[16px] top-0"
        data-name="Top Panel"
        data-node-id="4:501"
      >
        <div
          className="h-[44px] relative shrink-0 w-[205px]"
          data-name="Container"
          data-node-id="4:502"
        >
          <div
            className="absolute content-stretch flex flex-col h-[44px] items-start left-0 top-0 w-[150.688px]"
            data-name="Container"
            data-node-id="4:503"
          >
            <div
              className="h-[24px] relative shrink-0 w-full"
              data-name="Heading 2"
              data-node-id="4:504"
            >
              <p
                className="absolute capitalize font-['Arial:Bold',_sans-serif] leading-[24px] left-0 not-italic text-[#101828] text-[16px] text-nowrap top-[-2px] whitespace-pre"
                data-node-id="4:505"
              >
                Welcome, User Name
              </p>
            </div>
            <div
              className="content-stretch flex h-[20px] items-start relative shrink-0 w-full"
              data-name="Paragraph"
              data-node-id="4:506"
            >
              <p
                className="font-['Arial:Regular',_sans-serif] leading-[20px] not-italic relative shrink-0 text-[#6a7282] text-[14px] text-nowrap whitespace-pre"
                data-node-id="4:507"
              >{`Managing, Patient Name `}</p>
            </div>
          </div>
          <div
            className="absolute left-[205px] size-0 top-[22px]"
            data-name="Container"
            data-node-id="4:508"
          />
        </div>
        <div
          className="bg-[rgba(0,166,62,0.1)] h-[44px] rounded-[10px] shrink-0 w-[140px]"
          data-node-id="4:510"
        />
        <div
          className="absolute inset-[40.79%_11.65%_41.66%_87.33%]"
          data-name="Vector"
          data-node-id="4:512"
        >
          <div className="absolute inset-[-5%_-5.55%]">
            <img
              alt=""
              className="block max-w-none size-full"
              src={imgVector}
            />
          </div>
        </div>
        <p
          className="absolute font-['Arial:Regular',_sans-serif] h-[22px] leading-[20px] left-[1063px] not-italic text-[#364135] text-[14px] top-[29px] w-[73px]"
          data-node-id="4:516"
        >
          Connected
        </p>
      </div>
      <div
        className="absolute bg-white border-[0px_1px_0px_0px] border-gray-200 border-solid h-[1024px] left-0 top-0 w-[256px]"
        data-name="Side Panel"
        data-node-id="75:914"
      >
        <div
          className="absolute border-[0px_0px_1px] border-gray-200 border-solid box-border content-stretch flex flex-col h-[89px] items-start left-0 pb-px pt-[24px] px-[24px] top-0 w-[255px]"
          data-name="Name + Icon"
          data-node-id="75:915"
        >
          <div
            className="content-stretch flex gap-[12px] h-[40px] items-center relative shrink-0 w-full"
            data-name="Container"
            data-node-id="75:916"
          >
            <div
              className="h-[40px] relative shrink-0 w-[98.563px]"
              data-name="Container"
              data-node-id="75:917"
            >
              <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border content-stretch flex flex-col h-[40px] items-start relative w-[98.563px]">
                <div
                  className="h-[24px] relative shrink-0 w-full"
                  data-name="Heading 1"
                  data-node-id="75:918"
                >
                  <p
                    className="absolute font-['Arial:Bold',_sans-serif] leading-[24px] left-0 not-italic text-[#101828] text-[16px] text-nowrap top-[-2px] whitespace-pre"
                    data-node-id="75:919"
                  >
                    DCM Console
                  </p>
                </div>
                <div
                  className="content-stretch flex h-[16px] items-start relative shrink-0 w-[146px]"
                  data-name="Paragraph"
                  data-node-id="75:920"
                >
                  <p
                    className="basis-0 font-['Arial:Regular',_sans-serif] grow leading-[16px] min-h-px min-w-px not-italic relative shrink-0 text-[#6a7282] text-[12px]"
                    data-node-id="75:921"
                  >{`Device Control Monitor `}</p>
                </div>
              </div>
            </div>
          </div>
        </div>
        <div
          className="absolute content-stretch flex flex-col h-[748px] items-start left-[12px] overflow-clip top-[105px] w-[231px]"
          data-name="Side Panel Buttons"
          data-node-id="75:922"
        >
          <div
            className="content-stretch flex flex-col gap-[22px] h-[528px] items-start relative shrink-0 w-full"
            data-name="App"
            data-node-id="75:923"
          >
            <div
              className="content-stretch flex flex-col gap-[12px] h-[64px] items-start relative shrink-0 w-full"
              data-name="Patient Management"
              data-node-id="75:924"
            >
              <div
                className="box-border content-stretch flex h-[16px] items-start px-[12px] py-0 relative shrink-0 w-full"
                data-name="Heading 3"
                data-node-id="75:925"
              >
                <p
                  className="basis-0 font-['Arial:Regular',_sans-serif] grow leading-[16px] min-h-px min-w-px not-italic relative shrink-0 text-[#6a7282] text-[12px] tracking-[0.6px] uppercase"
                  data-node-id="75:926"
                >
                  Patient Management
                </p>
              </div>
              <div
                className="content-stretch flex flex-col gap-[4px] h-[36px] items-start relative shrink-0 w-full"
                data-name="Container"
                data-node-id="75:927"
              >
                <div
                  className="bg-[rgba(21,93,252,0.1)] box-border content-stretch flex gap-[12px] h-[36px] items-center px-[12px] py-0 relative rounded-[10px] shrink-0 w-full"
                  data-name="Button"
                  data-node-id="75:928"
                >
                  <div
                    className="relative shrink-0 size-[16px]"
                    data-name="Icon"
                    data-node-id="75:929"
                  >
                    <img
                      alt=""
                      className="block max-w-none size-full"
                      src={imgIcon1}
                    />
                  </div>
                  <div
                    className="basis-0 grow h-[20px] min-h-px min-w-px relative shrink-0"
                    data-name="Text"
                    data-node-id="75:934"
                  >
                    <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border content-stretch flex h-[20px] items-start relative w-full">
                      <p
                        className="font-['Arial:Regular',_sans-serif] leading-[20px] not-italic relative shrink-0 text-[#364135] text-[14px] text-nowrap whitespace-pre"
                        data-node-id="75:935"
                      >
                        Patients
                      </p>
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <div
              className="content-stretch flex flex-col gap-[12px] h-[104px] items-start relative shrink-0 w-full"
              data-name="Device Operations"
              data-node-id="75:936"
            >
              <div
                className="box-border content-stretch flex h-[16px] items-start px-[12px] py-0 relative shrink-0 w-full"
                data-name="Heading 3"
                data-node-id="75:937"
              >
                <p
                  className="basis-0 font-['Arial:Regular',_sans-serif] grow leading-[16px] min-h-px min-w-px not-italic relative shrink-0 text-[#6a7282] text-[12px] tracking-[0.6px] uppercase"
                  data-node-id="75:938"
                >
                  Device Operations
                </p>
              </div>
              <div
                className="content-stretch flex flex-col gap-[4px] h-[116px] items-start relative shrink-0 w-full"
                data-name="Container"
                data-node-id="75:939"
              >
                <div
                  className="box-border content-stretch flex gap-[12px] h-[36px] items-center pl-[12px] pr-0 py-0 relative rounded-[10px] shrink-0 w-full"
                  data-name="Button"
                  data-node-id="75:940"
                >
                  <div
                    className="relative shrink-0 size-[16px]"
                    data-name="Icon"
                    data-node-id="75:941"
                  >
                    <img
                      alt=""
                      className="block max-w-none size-full"
                      src={imgIcon2}
                    />
                  </div>
                  <div
                    className="h-[20px] relative shrink-0 w-[71.141px]"
                    data-name="Text"
                    data-node-id="75:944"
                  >
                    <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border content-stretch flex h-[20px] items-start relative w-[71.141px]">
                      <p
                        className="font-['Arial:Regular',_sans-serif] leading-[20px] not-italic relative shrink-0 text-[#364153] text-[14px] text-nowrap whitespace-pre"
                        data-node-id="75:945"
                      >
                        Parameters
                      </p>
                    </div>
                  </div>
                </div>
                <div
                  className="box-border content-stretch flex gap-[12px] h-[36px] items-center pl-[12px] pr-0 py-0 relative rounded-[10px] shrink-0 w-full"
                  data-name="Button"
                  data-node-id="75:946"
                >
                  <div
                    className="relative shrink-0 size-[16px]"
                    data-name="Icon"
                    data-node-id="75:947"
                  >
                    <img
                      alt=""
                      className="block max-w-none size-full"
                      src={imgIcon3}
                    />
                  </div>
                  <div
                    className="h-[20px] relative shrink-0 w-[76.734px]"
                    data-name="Text"
                    data-node-id="75:949"
                  >
                    <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border content-stretch flex h-[20px] items-start relative w-[76.734px]">
                      <p
                        className="font-['Arial:Regular',_sans-serif] leading-[20px] not-italic relative shrink-0 text-[#364153] text-[14px] text-nowrap whitespace-pre"
                        data-node-id="75:950"
                      >
                        Electrogram
                      </p>
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <div
              className="content-stretch flex flex-col gap-[12px] h-[64px] items-start relative shrink-0 w-full"
              data-name="Data and Reports"
              data-node-id="75:951"
            >
              <div
                className="box-border content-stretch flex h-[16px] items-start px-[12px] py-0 relative shrink-0 w-full"
                data-name="Heading 3"
                data-node-id="75:952"
              >
                <p
                  className="basis-0 font-['Arial:Regular',_sans-serif] grow leading-[16px] min-h-px min-w-px not-italic relative shrink-0 text-[#6a7282] text-[12px] tracking-[0.6px] uppercase"
                  data-node-id="75:953"
                >{`Data & Reports`}</p>
              </div>
              <div
                className="content-stretch flex flex-col gap-[4px] h-[36px] items-start relative shrink-0 w-full"
                data-name="Container"
                data-node-id="75:954"
              >
                <div
                  className="box-border content-stretch flex gap-[12px] h-[36px] items-center pl-[12px] pr-0 py-0 relative rounded-[10px] shrink-0 w-full"
                  data-name="Button"
                  data-node-id="75:955"
                >
                  <div
                    className="relative shrink-0 size-[16px]"
                    data-name="Icon"
                    data-node-id="75:956"
                  >
                    <img
                      alt=""
                      className="block max-w-none size-full"
                      src={imgIcon4}
                    />
                  </div>
                  <div
                    className="h-[20px] relative shrink-0 w-[49.266px]"
                    data-name="Text"
                    data-node-id="75:962"
                  >
                    <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border content-stretch flex h-[20px] items-start relative w-[49.266px]">
                      <p
                        className="font-['Arial:Regular',_sans-serif] leading-[20px] not-italic relative shrink-0 text-[#364153] text-[14px] text-nowrap whitespace-pre"
                        data-node-id="75:963"
                      >
                        Reports
                      </p>
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <div
              className="content-stretch flex flex-col gap-[12px] h-[64px] items-start relative shrink-0 w-full"
              data-name="System"
              data-node-id="75:964"
            >
              <div
                className="box-border content-stretch flex h-[16px] items-start px-[12px] py-0 relative shrink-0 w-full"
                data-name="Heading 3"
                data-node-id="75:965"
              >
                <p
                  className="basis-0 font-['Arial:Regular',_sans-serif] grow leading-[16px] min-h-px min-w-px not-italic relative shrink-0 text-[#6a7282] text-[12px] tracking-[0.6px] uppercase"
                  data-node-id="75:966"
                >
                  System
                </p>
              </div>
              <div
                className="box-border content-stretch flex gap-[12px] h-[36px] items-center pl-[12px] pr-0 py-0 relative rounded-[10px] shrink-0 w-full"
                data-name="Button"
                data-node-id="75:967"
              >
                <div
                  className="relative shrink-0 size-[16px]"
                  data-name="Icon"
                  data-node-id="75:968"
                >
                  <img
                    alt=""
                    className="block max-w-none size-full"
                    src={imgIcon5}
                  />
                </div>
                <div
                  className="h-[20px] relative shrink-0 w-[39.438px]"
                  data-name="Text"
                  data-node-id="75:972"
                >
                  <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border content-stretch flex h-[20px] items-start relative w-[39.438px]">
                    <p
                      className="basis-0 font-['Arial:Regular',_sans-serif] grow leading-[20px] min-h-px min-w-px not-italic relative shrink-0 text-[#364153] text-[14px]"
                      data-node-id="75:973"
                    >
                      About
                    </p>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
        <div
          className="absolute box-border content-stretch flex gap-[12px] h-[48px] items-center left-[9px] pl-[12px] pr-0 py-0 rounded-[10px] top-[953px] w-[231px]"
          data-name="Button"
          data-node-id="75:974"
        >
          <div
            className="relative shrink-0 size-[16px]"
            data-name="Icon"
            data-node-id="75:975"
          >
            <img alt="" className="block max-w-none size-full" src={imgIcon6} />
          </div>
          <div
            className="h-[20px] relative shrink-0 w-[39.438px]"
            data-name="Text"
            data-node-id="75:979"
          >
            <div className="bg-clip-padding border-0 border-[transparent] border-solid box-border content-stretch flex h-[20px] items-start relative w-[39.438px]">
              <p
                className="font-['Arial:Regular',_sans-serif] leading-[20px] not-italic relative shrink-0 text-[#364153] text-[14px] w-[74px]"
                data-node-id="75:980"
              >
                Sign Out
              </p>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
